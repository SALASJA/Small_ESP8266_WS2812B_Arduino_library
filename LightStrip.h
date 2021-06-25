#ifndef LIGHT_STRIP_H
#define LIGHT_STRIP_H
#include <cstdint>
#include <cstdlib>
#include "esp8266_protocol.h"


class LightStrip {
	private:
		uint8_t * pixels;
		uint32_t num_leds;
		uint8_t pin;
		uint32_t endTime;
		
	public: 
		LightStrip(uint32_t num_leds);
		~LightStrip();
		void setOutput(uint8_t pin);
		uint8_t set_pixel(uint16_t index, double red, double green, double blue);
		void begin();
		bool canShow();
		void sync();
};
#endif 

