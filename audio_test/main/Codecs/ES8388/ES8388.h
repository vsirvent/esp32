/*
	ES8388 - An ES8388 Codec driver library for Arduino
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ES8388_H
#define ES8388_H

#include <inttypes.h>

#include "driver/i2c.h"

#include "../AudioDriver.h"

class ES8388: public AudioDriver {

public:

	typedef enum {
		SAMPLE_RATE_8000	= 0x0000,
		SAMPLE_RATE_11052	= 0x1000,
		SAMPLE_RATE_12000	= 0x2000,
		SAMPLE_RATE_16000	= 0x3000,
		SAMPLE_RATE_22050	= 0x4000,
		SAMPLE_RATE_24000	= 0x5000,
		SAMPLE_RATE_32000	= 0x6000,
		SAMPLE_RATE_44100	= 0x7000,
		SAMPLE_RATE_48000	= 0x8000,
		SAMPLE_RATE_96000	= 0x9000,
		SAMPLE_RATE_192000	= 0xa000,
	} I2sSampleRate_t;

	typedef enum {
		MODE_MASTER			= 0x00,
		MODE_SLAVE			= 0x01,
	} I2sMode_t;

	typedef enum {
		WORD_SIZE_8_BITS	= 0x00,
		WORD_SIZE_16_BITS	= 0x01,
		WORD_SIZE_20_BITS	= 0x02,
		WORD_SIZE_24_BITS	= 0x03,
	} I2sWordSize_t;

	typedef enum {
		DATA_FORMAT_I2S		= 0x00,
		DATA_FORMAT_LEFT	= 0x01,
		DATA_FORMAT_RIGHT	= 0x02,
		DATA_FORMAT_DSP		= 0x03,
	} I2sFormat_t;

	typedef enum {
		BCLK_DIV_1			= 0x0,
		BCLK_DIV_2			= 0x1,
		BCLK_DIV_4			= 0x2,
		BCLK_DIV_6			= 0x3,
		BCLK_DIV_8			= 0x4,
		BCLK_DIV_12			= 0x5,
		BCLK_DIV_16			= 0x6,
		BCLK_DIV_24			= 0x7,
		BCLK_DIV_32			= 0x8,
		BCLK_DIV_48			= 0x9,
		BCLK_DIV_64			= 0xa,
		BCLK_DIV_96			= 0xb,
		BCLK_DIV_128		= 0xc,
		BCLK_DIV_192		= 0xd,
	} I2sBitClockDiv_t;

	typedef enum {
		LRCK_DIV_16			= 0x0,
		LRCK_DIV_32			= 0x1,
		LRCK_DIV_64			= 0x2,
		LRCK_DIV_128		= 0x3,
		LRCK_DIV_256		= 0x4,
	} I2sLrClockDiv_t;


	typedef enum {
		MODE_ADC = 0x01,
		MODE_DAC = 0x02,
		MODE_ADC_DAC = 0x03,
		MODE_LINE = 0x04,
	} Mode_t;

	typedef enum {
		BIT_LENGTH_16BITS = 0x03,
		BIT_LENGTH_18BITS = 0x02,
		BIT_LENGTH_20BITS = 0x01,
		BIT_LENGTH_24BITS = 0x00,
		BIT_LENGTH_32BITS = 0x04,
	} Bits_t;

	typedef enum {
		DAC_OUTPUT_LOUT1 = 0x04,
		DAC_OUTPUT_LOUT2 = 0x08,
		DAC_OUTPUT_SPK   = 0x09,
		DAC_OUTPUT_ROUT1 = 0x10,
		DAC_OUTPUT_ROUT2 = 0x20,
		DAC_OUTPUT_ALL = 0x3c,
	} DACOutput_t;

	typedef enum {
		ADC_INPUT_LINPUT1_RINPUT1 = 0x00,
		ADC_INPUT_MIC1  = 0x05,
		ADC_INPUT_MIC2  = 0x06,
		ADC_INPUT_LINPUT2_RINPUT2 = 0x50,
		ADC_INPUT_DIFFERENCE = 0xf0,
	} ADCInput_t;

	typedef enum {
		MIC_GAIN_0DB = 0,
		MIC_GAIN_3DB = 3,
		MIC_GAIN_6DB = 6,
		MIC_GAIN_9DB = 9,
		MIC_GAIN_12DB = 12,
		MIC_GAIN_15DB = 15,
		MIC_GAIN_18DB = 18,
		MIC_GAIN_21DB = 21,
		MIC_GAIN_24DB = 24,
	} MicGain_t;

	typedef enum {
		MCLK_DIV_MIN = -1,
		MCLK_DIV_1 = 1,
		MCLK_DIV_2 = 2,
		MCLK_DIV_3 = 3,
		MCLK_DIV_4 = 4,
		MCLK_DIV_6 = 5,
		MCLK_DIV_8 = 6,
		MCLK_DIV_9 = 7,
		MCLK_DIV_11 = 8,
		MCLK_DIV_12 = 9,
		MCLK_DIV_16 = 10,
		MCLK_DIV_18 = 11,
		MCLK_DIV_22 = 12,
		MCLK_DIV_24 = 13,
		MCLK_DIV_33 = 14,
		MCLK_DIV_36 = 15,
		MCLK_DIV_44 = 16,
		MCLK_DIV_48 = 17,
		MCLK_DIV_66 = 18,
		MCLK_DIV_72 = 19,
		MCLK_DIV_5 = 20,
		MCLK_DIV_10 = 21,
		MCLK_DIV_15 = 22,
		MCLK_DIV_17 = 23,
		MCLK_DIV_20 = 24,
		MCLK_DIV_25 = 25,
		MCLK_DIV_30 = 26,
		MCLK_DIV_32 = 27,
		MCLK_DIV_34 = 28,
		MCLK_DIV_7  = 29,
		MCLK_DIV_13 = 30,
		MCLK_DIV_14 = 31,
		MCLK_DIV_MAX,
	} sclk_div_t;

	typedef enum {
		LCLK_DIV_MIN = -1,
		LCLK_DIV_128 = 0,
		LCLK_DIV_192 = 1,
		LCLK_DIV_256 = 2,
		LCLK_DIV_384 = 3,
		LCLK_DIV_512 = 4,
		LCLK_DIV_576 = 5,
		LCLK_DIV_768 = 6,
		LCLK_DIV_1024 = 7,
		LCLK_DIV_1152 = 8,
		LCLK_DIV_1408 = 9,
		LCLK_DIV_1536 = 10,
		LCLK_DIV_2112 = 11,
		LCLK_DIV_2304 = 12,

		LCLK_DIV_125 = 16,
		LCLK_DIV_136 = 17,
		LCLK_DIV_250 = 18,
		LCLK_DIV_272 = 19,
		LCLK_DIV_375 = 20,
		LCLK_DIV_500 = 21,
		LCLK_DIV_544 = 22,
		LCLK_DIV_750 = 23,
		LCLK_DIV_1000 = 24,
		LCLK_DIV_1088 = 25,
		LCLK_DIV_1496 = 26,
		LCLK_DIV_1500 = 27,
		LCLK_DIV_MAX,
	} lclk_div_t;


	typedef struct {
    	sclk_div_t sclk_div;    /*!< bits clock divide */
    	lclk_div_t lclk_div;    /*!< WS clock divide */
	} I2SClock_t;

	// Constructor/Destructor
  	ES8388();
	virtual ~ES8388();

	// Convenience method
	int setup(int fs, 
	          int channelCount, 
			  int bitClkPin, int lrClkPin, int mClkPin,
			  int dataOutPin, int dataInPin, 
			  int enablePin, i2s_port_t i2sPort);

	void setI2CPins(int i2c_scl = GPIO_NUM_32, int i2c_data = GPIO_NUM_33);

	// Initialize codec with give sample rate
	// @return True on success, false on failure.
	bool begin(int fs);

	bool SetI2sSampleRate(I2sSampleRate_t rate);
	bool SetI2sFormat(Mode_t mode, I2sFormat_t format);
	bool SetI2sWordSize(I2sWordSize_t size);
	bool SetI2sClock(I2SClock_t clock);

	bool SetBitsPerSample(Mode_t mode, Bits_t bits_length);
	bool Start(Mode_t mode);
	bool Stop(Mode_t mode);
	bool SetVoiceMute(bool enable);
	bool GetVoiceMute(bool* enable);
	bool SetVoiceVolume(int volume);
	bool GetVoiceVolume(int* volume);
	bool SetDACOutput(DACOutput_t output, bool enable);
	bool SetADCInput(ADCInput_t input);
	bool SetMicGain(MicGain_t gain);
	bool SetPAPower(bool enable);
	bool SetVolume(Mode_t mode, int volume, int dot);

	// Dumpt the current register configuration to serial.
	void DumpRegisters();
	
	uint16_t GetDeviceID();

	virtual const char* GetTag() override {
		return TAG;
	}
	
protected:

	bool WriteReg(uint8_t reg, uint8_t data);
	bool ReadReg(uint8_t reg, uint8_t* data);
	
	int enable_pin;

	int I2C_SCL;
	int I2C_SDA;
    
	static const char* TAG;
};

#endif
