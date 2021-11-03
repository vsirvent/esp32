/*
 * 	AudioDriver.h
 *
 *  Author: Gary Grutzek
 * 	gary@ib-gru.de
 */

#ifndef AUDIODRIVER_H_
#define AUDIODRIVER_H_

// include espressif hw files
#include "driver/gpio.h"
#include "driver/i2s.h"

class AudioDriver {

public:

	static const int buffer_size = 256;
public:
	
	esp_err_t start();

	virtual esp_err_t I2SSetUp(int fs, 
	          int bitClkPin, int lrClkPin, int mClkPin,
			  int dataOutPin, int dataInPin, i2s_port_t i2sPort);

	esp_err_t readBlock(uint16_t* buffer, int size, size_t* read);
	esp_err_t writeBlock(const int16_t* buffer, int size, size_t* write);

	virtual const char* GetTag() = 0;

protected:

	int fs;
	int channelCount;
	i2s_port_t i2sPort;
};



#endif /* AUDIODRIVER_H_ */
