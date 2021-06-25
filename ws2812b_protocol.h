// This is a mash-up of the Due show() code + insights from Michael Miller's
// ESP8266 work for the NeoPixelBus library: github.com/Makuna/NeoPixelBus
// Needs to be a separate .c file to enforce ICACHE_RAM_ATTR execution.

#ifndef ESP8266_PROTOCOL_H
#define ESP8266_PROTOCOL_H
#include <Arduino.h>
#include <eagle_soc.h>
#include <cstdint>


#define CYCLES_800_T0H  (F_CPU / 2500000) // 0.4us
#define CYCLES_800_T1H  (F_CPU / 1250000) // 0.8us
#define CYCLES_800      (F_CPU /  800000) // 1.25us per bit


void ICACHE_RAM_ATTR espShow(uint8_t pin, uint8_t *pixels, uint32_t numBytes);

#endif // ESP8266
