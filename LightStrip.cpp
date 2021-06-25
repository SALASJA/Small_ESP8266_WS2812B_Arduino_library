#include "LightStrip.h"

LightStrip::LightStrip(uint32_t num_leds) {
	this->num_leds = num_leds;
	this->pixels = (uint8_t*)malloc(this->num_leds * 3);
	for(int i = 0; i < this->num_leds * 3; i = i + 1){
	  this->pixels[i] = 0;
	}
	endTime = 0;
}


void LightStrip::sync() {
  while(!canShow());
  espShow(this->pin, this->pixels, this->num_leds * 3); 
  this->endTime = micros();
}


LightStrip::~LightStrip() {
	free(pixels);
}


void LightStrip::setOutput(uint8_t pin) {
  this->pin = pin;
}

uint8_t LightStrip::set_pixel(uint16_t index, double red, double green, double blue) {
	if(index < this->num_leds) {
		uint16_t tmp;
		tmp = index * 3;
		this->pixels[tmp + 1] = (uint8_t)red;
		this->pixels[tmp + 2] = (uint8_t)green;
		this->pixels[tmp + 0] = (uint8_t)blue;
		return 0;
	} 
	return 1;
}

void LightStrip::begin() {
  if(this->pin >= 0) {
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, LOW);
  }
}


bool LightStrip::canShow() {
    if (this->endTime > micros()) {
      this->endTime = micros();
    }
    return (micros() - this->endTime) >= 300L;
}



