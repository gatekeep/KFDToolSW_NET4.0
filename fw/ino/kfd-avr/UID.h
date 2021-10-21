#ifndef UID_H_
#define UID_H_

#include <Arduino.h>

#if defined(ARDUINO_ARCH_AVR)
#include <avr/boot.h>
#ifndef SIGRD
#define SIGRD 5
#endif
#elif defined(ARDUINO_ARCH_ESP8266)
#elif defined(ARDUINO_ARCH_ESP32)
#elif defined(ARDUINO_ARCH_SAM)
#elif defined(ARDUINO_ARCH_SAMD)
#elif defined(ARDUINO_ARCH_STM32)
#else
#error "ArduinoUniqueID only works on AVR, SAM, SAMD, STM32 and ESP Architecture"
#endif

#if defined(ARDUINO_ARCH_AVR)

#if defined(__AVR_ATmega328PB__)
#define UniqueIDsize 10
#else
#define UniqueIDsize 9
#endif

#define UniqueIDbuffer UniqueIDsize

#elif defined(ARDUINO_ARCH_ESP8266)
#define UniqueIDsize 4
#define UniqueIDbuffer 8
#elif defined(ARDUINO_ARCH_ESP32)
#define UniqueIDsize 6
#define UniqueIDbuffer 8
#elif defined(ARDUINO_ARCH_SAM)
#define UniqueIDsize 16
#define UniqueIDbuffer 16
#elif defined(ARDUINO_ARCH_SAMD)
#define UniqueIDsize 16
#define UniqueIDbuffer 16
#elif defined(ARDUINO_ARCH_STM32)
#define UniqueIDsize 12
#define UniqueIDbuffer 12
#endif


void getUID8(uint8_t *id0, uint8_t *id1, uint8_t *id2, uint8_t *id3, uint8_t *id4, uint8_t *id5, uint8_t *id6, uint8_t *id7);

#endif
