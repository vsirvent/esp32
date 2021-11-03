/*
	ES8388 - An ES8388 Codec driver library for esp-idf
	
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

#include <stdio.h>
#include <string.h>

#include "esp_system.h"
#include "esp_log.h"
#include "esp_check.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/i2s.h"

#include "ES8388.h"

#define I2C_NUM         	(0)			
/* ES8388 address */
#define ES8388_ADDR 0x20  /*!< 0x22:CE=1;0x20:CE=0*/
#define ES8388_ID   0x06  /* Register 0x00 default value */

/* ES8388 register */
#define ES8388_CONTROL1         0x00
#define ES8388_CONTROL2         0x01

#define ES8388_CHIPPOWER        0x02

#define ES8388_ADCPOWER         0x03
#define ES8388_DACPOWER         0x04

#define ES8388_CHIPLOPOW1       0x05
#define ES8388_CHIPLOPOW2       0x06

#define ES8388_ANAVOLMANAG      0x07

#define ES8388_MASTERMODE       0x08
/* ADC */
#define ES8388_ADCCONTROL1      0x09
#define ES8388_ADCCONTROL2      0x0a
#define ES8388_ADCCONTROL3      0x0b
#define ES8388_ADCCONTROL4      0x0c
#define ES8388_ADCCONTROL5      0x0d
#define ES8388_ADCCONTROL6      0x0e
#define ES8388_ADCCONTROL7      0x0f
#define ES8388_ADCCONTROL8      0x10
#define ES8388_ADCCONTROL9      0x11
#define ES8388_ADCCONTROL10     0x12
#define ES8388_ADCCONTROL11     0x13
#define ES8388_ADCCONTROL12     0x14
#define ES8388_ADCCONTROL13     0x15
#define ES8388_ADCCONTROL14     0x16
/* DAC */
#define ES8388_DACCONTROL1      0x17
#define ES8388_DACCONTROL2      0x18
#define ES8388_DACCONTROL3      0x19
#define ES8388_DACCONTROL4      0x1a
#define ES8388_DACCONTROL5      0x1b
#define ES8388_DACCONTROL6      0x1c
#define ES8388_DACCONTROL7      0x1d
#define ES8388_DACCONTROL8      0x1e
#define ES8388_DACCONTROL9      0x1f
#define ES8388_DACCONTROL10     0x20
#define ES8388_DACCONTROL11     0x21
#define ES8388_DACCONTROL12     0x22
#define ES8388_DACCONTROL13     0x23
#define ES8388_DACCONTROL14     0x24
#define ES8388_DACCONTROL15     0x25
#define ES8388_DACCONTROL16     0x26
#define ES8388_DACCONTROL17     0x27
#define ES8388_DACCONTROL18     0x28
#define ES8388_DACCONTROL19     0x29
#define ES8388_DACCONTROL20     0x2a
#define ES8388_DACCONTROL21     0x2b
#define ES8388_DACCONTROL22     0x2c
#define ES8388_DACCONTROL23     0x2d
#define ES8388_DACCONTROL24     0x2e
#define ES8388_DACCONTROL25     0x2f
#define ES8388_DACCONTROL26     0x30
#define ES8388_DACCONTROL27     0x31
#define ES8388_DACCONTROL28     0x32
#define ES8388_DACCONTROL29     0x33
#define ES8388_DACCONTROL30     0x34

#define ARRAY_SIZE(x)  (sizeof(x)/sizeof(x[0]))

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

const char* ES8388::TAG = "ES8388";

bool ES8388::WriteReg(uint8_t reg, uint8_t data)
{
	esp_err_t  ret;
    //printf("==> Write Reg 0x%02x => " BYTE_TO_BINARY_PATTERN "\n", reg, BYTE_TO_BINARY(data));
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();
	//Queue all the commands to i2c driver
    ESP_GOTO_ON_ERROR(i2c_master_start(i2c_cmd), end, TAG, "i2c_master_start failed");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, ES8388_ADDR | I2C_MASTER_WRITE, true), end, TAG, "i2c_master_write_byte");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, reg, true), end, TAG, "i2c_master_write_byte");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, data, true), end, TAG, "i2c_master_write_byte");
    ESP_GOTO_ON_ERROR(i2c_master_stop(i2c_cmd), end, TAG, "i2c_master_stop");
	//Now send all the commands
    ESP_GOTO_ON_ERROR(i2c_master_cmd_begin(I2C_NUM, i2c_cmd, 1000 / portTICK_RATE_MS), end, TAG, "i2c_master_cmd_begin");
end:
    i2c_cmd_link_delete(i2c_cmd);
    return (ret == ESP_OK);
}

bool ES8388::ReadReg(uint8_t reg, uint8_t* data)
{
	esp_err_t  ret;
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();
	//Write commands to i2c queue
    ESP_GOTO_ON_ERROR(i2c_master_start(i2c_cmd), end, TAG, "i2c_master_start failed");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, ES8388_ADDR | I2C_MASTER_WRITE, true), end, TAG, "i2c_master_write_byte failed");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, reg, true), end, TAG, "i2c_master_write_byte failed");
    ESP_GOTO_ON_ERROR(i2c_master_start(i2c_cmd), end, TAG, "i2c_master_start failed");
    ESP_GOTO_ON_ERROR(i2c_master_write_byte(i2c_cmd, ES8388_ADDR | I2C_MASTER_READ, true), end, TAG, "i2c_master_write_byte failed");
    ESP_GOTO_ON_ERROR(i2c_master_read_byte(i2c_cmd, data, I2C_MASTER_LAST_NACK), end, TAG, "i2c_master_read_byte failed");
    ESP_GOTO_ON_ERROR(i2c_master_stop(i2c_cmd), end, TAG, "i2c_master_stop failed");
	//Flush commands
    ESP_GOTO_ON_ERROR(i2c_master_cmd_begin(I2C_NUM, i2c_cmd, 1000 / portTICK_RATE_MS), end, TAG, "i2c_master_cmd_begin failed");
end:
    i2c_cmd_link_delete(i2c_cmd);
	return (ret == ESP_OK);
}

ES8388::ES8388()
{
	SetI2CPins();
}

ES8388::~ES8388()
{
    WriteReg(ES8388_CHIPPOWER, 0xFF);  //reset and stop es8388
}

void ES8388::SetI2CPins(int i2c_clk, int i2c_data) {
	I2C_SCL = i2c_clk;
	I2C_SDA = i2c_data;
}

int ES8388::Setup(int fs, int channelCount, int bitClkPin, int lrClkPin, int mClkPin,
                  int dataOutPin, int dataInPin, int enablePin, i2s_port_t i2s_port) {
	esp_err_t ret = ESP_OK;
	uint16_t id = 0;
	this->fs = fs;
    this->enable_pin = enablePin;
    ESP_LOGI(TAG, "Initializing AudioDriver...");
    ESP_GOTO_ON_ERROR(AudioDriver::I2SSetUp(fs, bitClkPin, lrClkPin, mClkPin,
                                         dataOutPin, dataInPin, i2s_port), 
                                         end, TAG, "AudioDriver::setup failed");
    ESP_LOGI(TAG, "AudioDriver init OK");
    {
        ESP_LOGI(TAG, "Init PA enabe GPIO...");
        gpio_config_t  io_conf;
        memset(&io_conf, 0, sizeof(io_conf));
        io_conf.intr_type = GPIO_INTR_DISABLE;
        io_conf.mode = GPIO_MODE_OUTPUT;
        io_conf.pin_bit_mask = BIT64(enablePin);
        io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
        io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
        ESP_GOTO_ON_ERROR(gpio_config(&io_conf), end, TAG, "PA enable GPIO failed");
        ESP_LOGI(TAG, "PA enabe GPIO init OK");
    }

	{
	    ESP_LOGI(TAG, "Init I2C driver...");
    	/* Initialize I2C peripheral */
		i2c_config_t i2c_cfg = {
			.mode = I2C_MODE_MASTER,
			.sda_io_num = I2C_SDA,
			.scl_io_num = I2C_SCL,
			.sda_pullup_en = GPIO_PULLUP_ENABLE,
			.scl_pullup_en = GPIO_PULLUP_ENABLE,
			.master = {
				.clk_speed = 100000
			},
			.clk_flags = 0
		};
		ESP_LOGI(TAG, "I2C SLC = %d, SDA = %d", I2C_SCL, I2C_SDA);
		ESP_GOTO_ON_ERROR(i2c_param_config(I2C_NUM, &i2c_cfg), end, TAG, "config i2c failed");
		ESP_GOTO_ON_ERROR(i2c_driver_install(I2C_NUM, I2C_MODE_MASTER, 0, 0, 0), end, TAG, "install i2c driver failed");
		ESP_LOGI(TAG, "I2C driver initialized");
	}
	id = GetDeviceID();
	ESP_LOGI(TAG, "Audio Codec REG 0x00 = 0x%x\n", id);
    ESP_LOGI(TAG, "Setting up codec registers...");
    ret |= WriteReg(ES8388_DACCONTROL3, 0x00);
    /* Chip Control and Power Management */
    ret |= WriteReg(ES8388_CONTROL2, 0x50);
    
    ret |= WriteReg(ES8388_CHIPPOWER, 0x00); //normal all and power up all

    // Disable the internal DLL to improve 8K sample rate
    ret |= WriteReg(0x35, 0xA0);
    ret |= WriteReg(0x37, 0xD0);
    ret |= WriteReg(0x39, 0xD0);

    ret |= WriteReg(ES8388_MASTERMODE, 0x00); //CODEC IN I2S SLAVE MODE

    /* dac */
    ret |= WriteReg(ES8388_DACPOWER, 0xC0);  //disable DAC and disable Lout/Rout/1/2
    ret |= WriteReg(ES8388_CONTROL1, 0x12);  //Enfr=0,Play&Record Mode,(0x17-both of mic&paly)
//    ret |= WriteReg(ES8388_CONTROL2, 0);  //LPVrefBuf=0,Pdn_ana=0
    ret |= WriteReg(ES8388_DACCONTROL1, 0x18);//1a 0x18:16bit iis , 0x00:24
    ret |= WriteReg(ES8388_DACCONTROL2, 0x02);  //DACFsMode,SINGLE SPEED; DACFsRatio,256
    ret |= WriteReg(ES8388_DACCONTROL16, 0x00); // 0x00 audio on LIN1&RIN1,  0x09 LIN2&RIN2
    ret |= WriteReg(ES8388_DACCONTROL17, 0x87); // only left DAC to left mixer enable -15db
    ret |= WriteReg(ES8388_DACCONTROL20, 0x87); // only right DAC to right mixer enable -15db
    ret |= WriteReg(ES8388_DACCONTROL21, 0x80); //set internal ADC and DAC use the same LRCK clock, ADC LRCK as internal LRCK
    ret |= WriteReg(ES8388_DACCONTROL23, 0x00);   //vroi=0
    ret |= SetVolume(MODE_DAC, 0, 0);          // 0db
    
    /* adc */
    ret |= WriteReg(ES8388_ADCPOWER, 0xFF);
    ret |= WriteReg(ES8388_ADCCONTROL3, 0x02);
    ret |= WriteReg(ES8388_ADCCONTROL4, 0x0d); // Left/Right data, Left/Right justified mode, Bits length, I2S format
    ret |= WriteReg(ES8388_ADCCONTROL5, 0x02);  //ADCFsMode,singel SPEED,RATIO=256
    ret |= WriteReg(ES8388_ADCPOWER, 0x09); //Power on ADC, Enable LIN&RIN, Power off MICBIAS, set int1lp to low power mode
    //ALC for Microphone
    
    /* enable es8388 PA */
    ESP_LOGI(TAG, "Codec registers initialized");
   
    SetPAPower(true);
end:
	return ret;
}

bool ES8388::SetBitsPerSample(Mode_t mode, Bits_t bits_length)
{
    esp_err_t res = ESP_OK;
    uint8_t reg = 0;
    int bits = (int)bits_length;

    if (mode == MODE_ADC || mode == MODE_ADC_DAC) {
        res = ReadReg(ES8388_ADCCONTROL4, &reg);
        reg = reg & 0xe3;
        res |=  WriteReg(ES8388_ADCCONTROL4, reg | (bits << 2));
    }
    if (mode == MODE_DAC || mode == MODE_DAC) {
        res = ReadReg(ES8388_DACCONTROL1, &reg);
        reg = reg & 0xc7;
        res |= WriteReg(ES8388_DACCONTROL1, reg | (bits << 3));
    }
    return (res == ESP_OK);
}

bool ES8388::SetVolume(Mode_t mode, int volume, int dot) 
{
    int res = 0;
    if ( volume < -96 || volume > 0 ) {
        ESP_LOGW(TAG, "Warning: volume < -96! or > 0!\n");
        if (volume < -96)
            volume = -96;
        else
            volume = 0;
    }
    dot = (dot >= 5 ? 1 : 0);
    volume = (-volume << 1) + dot;
    if (mode == MODE_ADC || mode == MODE_ADC_DAC) {
        res |= WriteReg(ES8388_ADCCONTROL8, volume);
        res |= WriteReg(ES8388_ADCCONTROL9, volume);  //ADC Right Volume=0db
    }
    if (mode == MODE_DAC || mode == MODE_ADC_DAC) {
        res |= WriteReg(ES8388_DACCONTROL5, volume);
        res |= WriteReg(ES8388_DACCONTROL4, volume);
    }
    ESP_LOGI(TAG, "Set volume => %d", volume);
    return res == (ESP_OK);
}

void ES8388::DumpRegisters()
{
    for (int i = 0; i < 50; i++) {
        uint8_t reg = 0;
        ReadReg(i, &reg);
        printf("%x: %x\n", i, reg);
    }
}

bool ES8388::SetI2sFormat(Mode_t mode, I2sFormat_t format)
{
    esp_err_t res = ESP_OK;
    uint8_t reg = 0;
    if (mode == MODE_ADC || mode == MODE_ADC_DAC) {
        res = ReadReg(ES8388_ADCCONTROL4, &reg);
        reg = reg & 0xfc;
        res |= WriteReg(ES8388_ADCCONTROL4, reg | format);
    }
    if (mode == MODE_DAC || mode == MODE_ADC_DAC) {
        res = ReadReg(ES8388_DACCONTROL1, &reg);
        reg = reg & 0xf9;
        res |= WriteReg(ES8388_DACCONTROL1, reg | (format << 1));
    }
    return (res == ESP_OK);
}

uint16_t ES8388::GetDeviceID()
{
	uint8_t data;
	ReadReg(0x00, &data);
	return data;
}

bool ES8388::Start(Mode_t mode) 
{
	esp_err_t res = ESP_OK;
    uint8_t prev_data = 0, data = 0;
    ReadReg(ES8388_DACCONTROL21, &prev_data);
    if (mode == MODE_LINE) {
        res |= WriteReg(ES8388_DACCONTROL16, 0x09); // 0x00 audio on LIN1&RIN1,  0x09 LIN2&RIN2 by pass enable
        res |= WriteReg(ES8388_DACCONTROL17, 0x50); // left DAC to left mixer enable  and  LIN signal to left mixer enable 0db  : bupass enable
        res |= WriteReg(ES8388_DACCONTROL20, 0x50); // right DAC to right mixer enable  and  LIN signal to right mixer enable 0db : bupass enable
        res |= WriteReg(ES8388_DACCONTROL21, 0xC0); //enable adc
    } else {
        res |= WriteReg(ES8388_DACCONTROL21, 0x80);   //enable dac
    }
    ReadReg(ES8388_DACCONTROL21, &data);
    if (prev_data != data) {
        res |= WriteReg(ES8388_CHIPPOWER, 0xF0);   //start state machine
        // res |= WriteReg(ES8388_CONTROL1, 0x16);
        // res |= WriteReg(ES8388_CONTROL2, 0x50);
        res |= WriteReg(ES8388_CHIPPOWER, 0x00);   //start state machine
    }
    if (mode == MODE_ADC || mode == MODE_ADC_DAC || mode == MODE_LINE) {
        res |= WriteReg(ES8388_ADCPOWER, 0x00);   //power up adc and line in
    }
    if (mode == MODE_DAC || mode == MODE_ADC_DAC || mode == MODE_LINE) {
        res |= WriteReg(ES8388_DACPOWER, 0x3c);   //power up dac and line out
        //res |= SetVoiceMute(false);
        ESP_LOGI(TAG, "es8388_start default is mode: %d", mode);
    }
    AudioDriver::start();
    return (res == ESP_OK);
}

bool ES8388::Stop(Mode_t mode) 
{
    esp_err_t res = ESP_OK;
    if (mode == MODE_LINE) {
        res |= WriteReg(ES8388_DACCONTROL21, 0x80); //enable dac
        res |= WriteReg(ES8388_DACCONTROL16, 0x00); // 0x00 audio on LIN1&RIN1,  0x09 LIN2&RIN2
        res |= WriteReg(ES8388_DACCONTROL17, 0x90); // only left DAC to left mixer enable 0db
        res |= WriteReg(ES8388_DACCONTROL20, 0x90); // only right DAC to right mixer enable 0db
        return res;
    }
    if (mode == MODE_DAC || mode == MODE_ADC_DAC) {
        res |= WriteReg(ES8388_DACPOWER, 0x00);
        //res |= SetVoiceMute(true); 
    }
    if (mode == MODE_ADC || mode == MODE_ADC_DAC) {
        res |= WriteReg(ES8388_ADCPOWER, 0xFF);  //power down adc and line in
    }
    if (mode == MODE_ADC_DAC) {
        res |= WriteReg(ES8388_DACCONTROL21, 0x9C);  //disable mclk
    }
    return (res == ESP_OK);
}

bool ES8388::SetVoiceMute(bool enable) 
{
    esp_err_t res = ESP_OK;
    uint8_t reg = 0;
    res = ReadReg(ES8388_DACCONTROL3, &reg);
    reg = reg & 0xFB;
    res |= WriteReg(ES8388_DACCONTROL3, reg | (((int)enable) << 2));
    return (res == ESP_OK);
}

bool ES8388::GetVoiceMute(bool* enable)
{
    esp_err_t res = ESP_OK;
    uint8_t reg = 0;
    res = ReadReg(ES8388_DACCONTROL3, &reg);
    if (res == ESP_OK) {
        *enable = (reg & 0x04) >> 2;
    }
    return (res == ESP_OK);
}

bool ES8388::SetVoiceVolume(int volume)
{
    esp_err_t res = ESP_OK;
    if (volume < 0)
        volume = 0;
    else if (volume > 100)
        volume = 100;
    volume /= 3;
    res = WriteReg(ES8388_DACCONTROL24, 0x1E);
    res |= WriteReg(ES8388_DACCONTROL25, 0x1E);
    res |= WriteReg(ES8388_DACCONTROL26, 0x1E);
    res |= WriteReg(ES8388_DACCONTROL27, 0x1E);
    return res;
}

bool ES8388::GetVoiceVolume(int *volume)
{
    esp_err_t res = ESP_OK;
    uint8_t reg = 0;
    res = ReadReg(ES8388_DACCONTROL24, &reg);
    if (res == ESP_FAIL) {
        *volume = 0;
    } else {
        *volume = reg;
        *volume *= 3;
        if (*volume == 99)
            *volume = 100;
    }
    return res;
}


bool ES8388::SetDACOutput(DACOutput_t output, bool enable)
{
    esp_err_t res;
    uint8_t reg = 0;
    res = ReadReg(ES8388_DACPOWER, &reg);
    ESP_LOGI(TAG, "SetDACOutput current reg 0x%02x", reg);
    reg = reg & DAC_OUTPUT_ALL;
	if (enable) {
		reg |= output;
	} else {
		reg &= ~output;
	}
    ESP_LOGI(TAG, "SetDACOutput => 0x%02x", reg);
    res |= WriteReg(ES8388_DACPOWER, reg);
    return (res == ESP_OK);
}

bool ES8388::SetADCInput(ADCInput_t input)
{
    esp_err_t res;
    uint8_t reg = 0;
    res = ReadReg(ES8388_ADCCONTROL2, &reg);
    reg = reg & 0x0f;
    res |= WriteReg(ES8388_ADCCONTROL2, reg | input);
    ESP_LOGI(TAG, "SetADCInput => 0x%02x", reg);
    return (res == ESP_OK);
}

bool ES8388::SetMicGain(MicGain_t gain)
{
    esp_err_t res, gain_n;
    gain_n = (int)gain / 3;
    gain_n = (gain_n << 4) + gain_n;
    res = WriteReg(ES8388_ADCCONTROL1, gain_n); //MIC PGA
    return res;
}

bool ES8388::SetPAPower(bool enable)
{
    ESP_LOGI(TAG, "Set PA power => %d", enable);
    gpio_set_level((gpio_num_t)enable_pin, enable);
    return true;
}