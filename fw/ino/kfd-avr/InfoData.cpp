#include "InfoData.h"

#define INFOB_START (0x0)
#define INFOB_LENGTH (128)

#define INFOC_START (0x128)
#define INFOC_LENGTH (128)

uint16_t idWriteModelIdHwRev(uint8_t hwId, uint8_t hwRevMaj, uint8_t hwRevMin)
{

    // this isn't set up yet, so fail out
    return 0;
}

uint16_t idWriteSerNum(uint8_t ser0, uint8_t ser1, uint8_t ser2, uint8_t ser3, uint8_t ser4, uint8_t ser5)
{

    // this isn't set up yet, so fail out
    return 0;
}

uint16_t idReadModelId(uint8_t *hwId)
{
    // this isn't set up yet, so fail out
    return 0;
}

uint16_t idReadHwRev(uint8_t *hwRevMaj, uint8_t *hwRevMin)
{
    // this isn't set up yet, so fail out
    return 0;
}

uint16_t idReadSerNum(uint8_t *ser0, uint8_t *ser1, uint8_t *ser2, uint8_t *ser3, uint8_t *ser4, uint8_t *ser5)
{

    // 43 4f 46 46 45 45
    // C  O  F  F  E  E
    *ser0 = 0x43;
    *ser1 = 0x4f;
    *ser2 = 0x46;
    *ser3 = 0x46;
    *ser4 = 0x45;
    *ser5 = 0x45;

    return 1;
}
