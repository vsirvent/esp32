#include <esp_check.h>
#include "AudioDriver.h"

esp_err_t AudioDriver::I2SSetUp(int fs,
                       int bitClkPin, int lrClkPin, int mClkPin,
                       int dataOutPin, int dataInPin, i2s_port_t i2sPort) {
	esp_err_t ret = ESP_OK;
	this->i2s_port = i2sPort;
	this->fs = fs;
	
	static const i2s_config_t i2s_config = {
			.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_TX),
			.sample_rate = (uint32_t)fs,
			.bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
			.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
			.communication_format = I2S_COMM_FORMAT_STAND_I2S,
			.intr_alloc_flags = ESP_INTR_FLAG_LEVEL1 | ESP_INTR_FLAG_IRAM, // high interrupt priority
			.dma_buf_count = 2,
			.dma_buf_len = buffer_size,
			.use_apll = true,
			.tx_desc_auto_clear = true,
			.mclk_multiple = I2S_MCLK_MULTIPLE_256			
	};

	ESP_GOTO_ON_ERROR(i2s_driver_install(i2s_port, &i2s_config, 0, NULL),
				   	  end, GetTag(), "i2s_driver_install error");	


	// enable I2S master clock on GPIO0 for master mode
	static const i2s_pin_config_t pin_config = {
			.mck_io_num = mClkPin,
			.bck_io_num = bitClkPin,
			.ws_io_num = lrClkPin,
			.data_out_num = dataOutPin,
			.data_in_num = dataInPin
	};
	ESP_LOGI(GetTag(), "setPins: mck_io_num = %d, bck_io_num =%d, ws_io_num = %d, dataOutPin = %d, dataInPin = %d",
	 					mClkPin, bitClkPin, lrClkPin, dataOutPin, dataInPin);
	ESP_GOTO_ON_ERROR(i2s_set_pin(i2s_port, &pin_config),
					 end, GetTag(), "i2s_set_pin error");	
	
	ESP_LOGI(GetTag(), "I2S Initialized");
end:
	return (ret);
}

esp_err_t AudioDriver::I2SStart() {
	esp_err_t ret = ESP_OK;
	ESP_GOTO_ON_ERROR(i2s_start(i2s_port),
					  end, GetTag(), "i2s_start failed");
end:					  
 	return ret;
}

esp_err_t AudioDriver::I2SStop() {
	esp_err_t ret = ESP_OK;
	ESP_GOTO_ON_ERROR(i2s_stop(i2s_port),
					  end, GetTag(), "i2s_stop failed");
end:					  
 	return ret;
}

esp_err_t AudioDriver::readBlock(int16_t* buffer, int size, size_t* read) {
	size_t to_read = (size * sizeof(int16_t));
	int err = i2s_read(i2s_port, (void*) buffer, to_read, read, portMAX_DELAY);

	if (err != ESP_OK || *read < to_read) {
		ESP_LOGE(GetTag(), "I2S read error: read = %d, to_read = %d\n", *read, to_read);
	}
	*read /= sizeof(int16_t);
	return err;
}

esp_err_t AudioDriver::writeBlock(const int16_t* buffer, int size, size_t* write) {
	size_t to_write = (size * sizeof(int16_t));
	int err = i2s_write(i2s_port, (const char *) buffer, to_write, write, portMAX_DELAY);

	if (err != ESP_OK || *write < to_write) {
		ESP_LOGE(GetTag(), "I2S write error: write = %d, to_write = %d\n", *write, to_write);
	}
	*write /= sizeof(int16_t);
	return err;
}
