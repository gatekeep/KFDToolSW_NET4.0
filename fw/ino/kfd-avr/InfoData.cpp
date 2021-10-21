#include "InfoData.h"

#define INFOB_START 0x0
#define INFOB_LENGTH 5
#define INFOB_HEADER 0x10
#define INFOB_FOOTER 0x11

#define INFOC_START 0x128
#define INFOC_LENGTH 8
#define INFOC_HEADER 0x20
#define INFOC_FOOTER 0x22

uint16_t idWriteModelIdHwRev(uint8_t hwId, uint8_t hwRevMaj, uint8_t hwRevMin)
{

    uint8_t data[5];
    data[0] = INFOB_HEADER;
    data[1] = hwId;
    data[2] = hwRevMaj;
    data[3] = hwRevMin;
    data[4] = INFOB_FOOTER;
    
    for (int i=0; i<INFOB_LENGTH; i++)
    {
        // use update instead of write to possibly save eeprom cells from unnecessary writes
        EEPROM.update(INFOB_START+i, data[i]);
    }
    return 1;
}

uint16_t idWriteSerNum(uint8_t ser0, uint8_t ser1, uint8_t ser2, uint8_t ser3, uint8_t ser4, uint8_t ser5)
{
    uint8_t data[8];
    data[0] = INFOC_HEADER;
    data[1] = ser0;
    data[2] = ser1;
    data[3] = ser2;
    data[4] = ser3;
    data[5] = ser4;
    data[6] = ser5;
    data[7] = INFOC_FOOTER;
    
    for (int i=0; i<INFOC_LENGTH; i++)
    {
        // use update instead of write to possibly save eeprom cells from unnecessary writes
        EEPROM.update(INFOC_START+i, data[i]);
    }
    return 1;
}

uint16_t idReadModelId(uint8_t *hwId)
{
    uint8_t data[INFOB_LENGTH];

    for (int i=0; i<INFOB_LENGTH; i++)
    {
        data[i] = EEPROM.read(INFOB_START + i);
    }
    
    uint8_t header;
    uint8_t footer;

    header = data[0];
    footer = data[INFOB_LENGTH - 1];
    *hwId = data[1];
    
    if (header == INFOB_HEADER && footer == INFOB_FOOTER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint16_t idReadHwRev(uint8_t *hwRevMaj, uint8_t *hwRevMin)
{
    uint8_t data[INFOB_LENGTH];

    for (int i=0; i<INFOB_LENGTH; i++)
    {
        data[i] = EEPROM.read(INFOB_START + i);
    }
    
    uint8_t header;
    uint8_t footer;

    header = data[0];
    footer = data[INFOB_LENGTH - 1];
    *hwRevMaj = data[2];
    *hwRevMin = data[3];
    
    if (header == INFOB_HEADER && footer == INFOB_FOOTER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

uint16_t idReadSerNum(uint8_t *ser0, uint8_t *ser1, uint8_t *ser2, uint8_t *ser3, uint8_t *ser4, uint8_t *ser5)
{
    uint8_t data[INFOC_LENGTH];

    for (int i=0; i<INFOC_LENGTH; i++)
    {
        data[i] = EEPROM.read(INFOC_START + i);
    }
    
    uint8_t header;
    uint8_t footer;

    header = data[0];
    footer = data[INFOC_LENGTH - 1];
    *ser0 = data[1];
    *ser1 = data[2];
    *ser2 = data[3];
    *ser3 = data[4];
    *ser4 = data[5];
    *ser5 = data[6];
    
    if (header == INFOC_HEADER && footer == INFOC_FOOTER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
