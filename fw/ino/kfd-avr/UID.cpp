// adapted from ArduinoUniqueID by ricaun
// original copyright notice:
// Copyright © Luiz Henrique Cassettari. All rights reserved.
// Licensed under the MIT license.

#include "UID.h"

void getUID8(uint8_t *id0, uint8_t *id1, uint8_t *id2, uint8_t *id3, uint8_t *id4, uint8_t *id5, uint8_t *id6, uint8_t *id7)
{
  uint8_t id[8];

  #if defined(ARDUINO_ARCH_AVR)
  for (size_t i = 0; i < 8; i++)
  {
    id[i] = boot_signature_byte_get(0x0E + i + (UniqueIDsize == 9 && i > 5 ? 1 : 0));
  }
  #elif defined(ARDUINO_ARCH_ESP8266)
  uint32_t chipid = ESP.getChipId();
  id[0] = 0;
  id[1] = 0;
  id[2] = 0;
  id[3] = 0;
  id[4] = chipid >> 24;
  id[5] = chipid >> 16;
  id[6] = chipid >> 8;
  id[7] = chipid;

  #elif defined(ARDUINO_ARCH_ESP32)
  uint64_t chipid = ESP.getEfuseMac();
  id[0] = 0;
  id[1] = 0;
  id[2] = chipid;
  id[3] = chipid >> 8;
  id[4] = chipid >> 16;
  id[5] = chipid >> 24;
  id[6] = chipid >> 32;
  id[7] = chipid >> 40;

  #endif

  *id0 = id[0];
  *id1 = id[1];
  *id2 = id[2];
  *id3 = id[3];
  *id4 = id[4];
  *id5 = id[5];
  *id6 = id[6];
  *id7 = id[7];
}
