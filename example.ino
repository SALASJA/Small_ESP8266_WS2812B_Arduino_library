#include "LightStrip.h"
#define NUM_LEDS 64
#define PIN 2
LightStrip strip(NUM_LEDS);

void setup() {
    strip.setOutput(PIN);
    strip.begin();
}

void loop() {
  for(uint16_t i = 0; i < NUM_LEDS; i++){
    strip.set_pixel(i, 100.0, 0.0, 0.0);
    strip.sync();
    delay(50);
    strip.set_pixel(i, 0.0, 0.0, 0.0);
    strip.sync();
    delay(50);
  }
}
    
