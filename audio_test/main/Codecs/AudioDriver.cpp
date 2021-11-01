/*
 *  AudioDriver.cpp
 *
 *  Author: Gary Grutzek
 * 	gary@ib-gru.de
 *
 */
#include "AudioDriver.h"
#include "esp_check.h"


const float AudioDriver::ScaleFloat2Int = 8388608.f; // 2^23
const float AudioDriver::ScaleInt2Float = 0.0000000004656612873077392578125f; // 1 / 2^31

esp_err_t AudioDriver::setup(int fs, int channelCount,
                       int bitClkPin, int lrClkPin, int mClkPin,
                       int dataOutPin, int dataInPin, i2s_port_t i2sPort) {
	int mclk_fs = 384;
	esp_err_t ret = ESP_OK;
	setI2sPort(i2sPort);
	ESP_GOTO_ON_ERROR(setFormat(fs, channelCount, I2S_BITS_PER_SAMPLE_32BIT, 
					            I2S_COMM_FORMAT_STAND_I2S, CODEC_I2S_ALIGN, mclk_fs),
								end, GetTag(), "setFormat error");
	ESP_GOTO_ON_ERROR(setPins(bitClkPin, lrClkPin, mClkPin, dataOutPin, dataInPin),
					  end, GetTag(),"setPins() error");
	ESP_GOTO_ON_ERROR(start(),
					  end, GetTag(), "start() error");
end:
	return (ret);
}

void AudioDriver::setI2sPort(i2s_port_t i2s_port) {
	this->i2sPort = i2s_port;
}


esp_err_t AudioDriver::setFormat(int fs, int channelCount, i2s_bits_per_sample_t bitsPerSample, i2s_comm_format_t format, int alignment, int mclkFactor) {
	this->fs = fs;
	this->channelCount = channelCount;
	
	static const i2s_config_t i2s_config = {
			.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_TX),
			.sample_rate = (uint32_t)fs,
			.bits_per_sample = bitsPerSample,
			.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
			.communication_format = format,
			.intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // high interrupt priority
			.dma_buf_count = 2,
			.dma_buf_len = AudioDriver::BufferSize,
			.use_apll = true,
			.tx_desc_auto_clear = true,
			.fixed_mclk = fs * (int)mclkFactor,
			.mclk_multiple = I2S_MCLK_MULTIPLE_DEFAULT,
			.bits_per_chan = I2S_BITS_PER_CHAN_DEFAULT //means same than bits_per_sample
	};

	switch (alignment) {
		case CODEC_I2S_ALIGN: lshift = 8; break;
		case CODEC_LJ_RJ_ALIGN: lshift = 0; break;
		default: lshift = 8; break;
	}

	esp_err_t err = i2s_driver_install(i2sPort, &i2s_config, 0, NULL);

	return err;
}


esp_err_t AudioDriver::setPins(int bitClkPin, int lrClkPin, int mClkPin, int dataOutPin, int dataInPin) {
	static const i2s_pin_config_t pin_config = {
			.bck_io_num = bitClkPin,
			.ws_io_num = lrClkPin,
			.data_out_num = dataOutPin,
			.data_in_num = dataInPin
	};
	esp_err_t err = i2s_set_pin(i2sPort, &pin_config);
	return err;
}


esp_err_t AudioDriver::start() {

	esp_err_t ret = ESP_OK;
	// enable I2S master clock on GPIO0 for master mode
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
	//WRITE_PERI_REG(PIN_CTRL, READ_PERI_REG(PIN_CTRL) & 0xFFFFFFF0);
	SET_PERI_REG_BITS(PIN_CTRL, CLK_OUT1, 0, CLK_OUT1_S);

	ESP_GOTO_ON_ERROR(i2s_set_sample_rates(i2sPort, fs),
					  end, GetTag(), "i2s_set_sample_rates failed");

	ESP_GOTO_ON_ERROR(i2s_zero_dma_buffer(i2sPort),
					  end, GetTag(), "i2s_zero_dma_buffer failed");
	
	// I2S buffers
	i2sBufferSize =  channelCount * AudioDriver::BufferSize;

	i2sReadBuffer = (int32_t*) calloc(i2sBufferSize, sizeof(int32_t));
	i2sWriteBuffer = (int32_t*) calloc(i2sBufferSize, sizeof(int32_t));

	// wait for stable clock
	vTaskDelay(200);
end:
 	return ret;
}


int AudioDriver::readBlock() {
	uint bytesRead = 0;

	int err = i2s_read(i2sPort, (void*) i2sReadBuffer, i2sBufferSize * sizeof(int32_t), &bytesRead, 500);

	if (err || bytesRead < (i2sBufferSize * sizeof(int32_t))) {
		printf("I2S read error: ");
		printf("%d\n", bytesRead);
	}
	return err;
}


int AudioDriver::writeBlock() {
	uint bytesWritten = 0;

	int err = i2s_write(i2sPort, (const char *) i2sWriteBuffer, channelCount * AudioDriver::BufferSize * sizeof(int32_t), &bytesWritten, 500);

	if (bytesWritten < 1) {
		printf("I2S write error: ");
		printf("%d\n",bytesWritten);
	}
	return err;
}
