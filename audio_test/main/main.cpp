#include <stdlib.h>
#include <math.h>
#include <esp_check.h>
#include <esp_log.h>
#include "Codecs/ES8388/ES8388.h"

#define I2C_CLK                     32
#define I2S_DATA                    33

#define I2S_DIN_PIN             	  35
#define I2S_DOUT_PIN                26
#define I2S_LRCLK_PIN               25
#define I2S_BCK_PIN                 27
#define I2S_MCLK_PIN                0

#define PIN_PLAY                    (23)      // KEY 4
#define PIN_VOL_UP                  (18)      // KEY 5
#define PIN_VOL_DOWN                (5)       // KEY 6
#define GPIO_PA_EN                  (21)

extern const int16_t music_pcm_start[] asm("_binary_canon_pcm_start");
extern const int16_t music_pcm_end[]   asm("_binary_canon_pcm_end");

extern "C" {
static const char* TAG = "MainApp";

int app_main(void)
{
  const int fs = 16000;
  esp_err_t ret = ESP_OK;
  
  ESP_LOGI(TAG,"Audio test init");
  
  ES8388 codec;
  codec.Setup(fs, 
              I2C_CLK, I2S_DATA,
              I2S_BCK_PIN, I2S_LRCLK_PIN, I2S_MCLK_PIN,
              I2S_DOUT_PIN, I2S_DIN_PIN,
              GPIO_PA_EN, I2S_NUM_0);
  	
  codec.SetDACOutput(ES8388::DACOutput_t::DAC_OUTPUT_ALL, true); 
  codec.SetADCInput(ES8388::ADCInput_t::ADC_INPUT_LINPUT1_RINPUT1);
  codec.SetGain(ES8388::Mode_t::MODE_ADC_DAC, 0, 0);
  codec.SetDACVolume(100);
  codec.SetMicGain(ES8388::MicGain_t::MIC_GAIN_6DB);
  codec.Start(ES8388::Mode_t::MODE_ADC_DAC);
  codec.SetPAPower(false);  

  int16_t * data = new int16_t[32000];
  for (int i = 0; i < 16000; i++) {
    double step = (2.0*M_PI*(i*440.0))/16000.0;
    data[i*2] = (int)(4095.0*sin(step));
    data[i*2+1] = data[i*2];
  }

  while (true) {
      /* Write music to earphone */
      size_t write = 0;
      ESP_LOGI(TAG, "Sending music file...");
      //codec.writeBlock(data, read, &write);
      codec.writeBlock(music_pcm_start, (music_pcm_end - music_pcm_start), &write);
      ESP_LOGI(TAG, "Music sent");      
  }
  return ret;
}
}
