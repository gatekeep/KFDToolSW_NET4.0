#include "SerialProtocol.h"
#include <Arduino.h>

#define SOM_EOM 0x61
#define SOM_EOM_PLACEHOLDER 0x62
#define ESC 0x63
#define ESC_PLACEHOLDER 0x64

uint16_t inDataCount = 0;
uint8_t inData[128];
bool messageStarted = false;

void spConnect(void)
{
    Serial.begin(115200);
}

void spDisconnect(void)
{
    //__disable_interrupt();

    Serial.end();
}

uint16_t spRxData(uint8_t* outData)
{
    while (Serial.available() > 0) {
        inData[inDataCount] = Serial.read();
        inDataCount++;
    }

    // don't process partial frames
    if (inDataCount < 3 || inData[0] != SOM_EOM || inData[inDataCount - 1] != SOM_EOM)
    {
        return 0;
    }

    uint16_t inIndex;
    uint16_t outIndex;
    outIndex = 0;

    for (inIndex = 1; inIndex < inDataCount - 1; inIndex++) // skip SOM and EOM
    {
        if (inData[inIndex] == ESC)
        {
            inIndex++;

            if (inData[inIndex] == SOM_EOM_PLACEHOLDER)
            {
                outData[outIndex] = SOM_EOM;
            }
            else if (inData[inIndex] == ESC_PLACEHOLDER)
            {
                outData[outIndex] = ESC;
            }
        }
        else
        {
            outData[outIndex] = inData[inIndex];
        }

        outIndex++;
    }

    // we've already processed the message and set the pointer
    // reset the count (mark the buffer as free)
    inDataCount = 0;
    

    return outIndex;
}

uint16_t spFrameData(const uint8_t* inData,
                     uint16_t inLength,
                     uint8_t* outData)
{
    uint16_t escCharsNeeded = 0;
    uint16_t i;

    for (i = 0; i < inLength; i++)
    {
        if ((inData[i] == SOM_EOM) || (inData[i] == ESC))
        {
            escCharsNeeded++;
        }
    }

    uint16_t totalCharsNeeded = 1 + inLength + escCharsNeeded + 1;

    *(outData + 0) = SOM_EOM;

    uint16_t j;
    uint16_t k = 1;

    for (j = 0; j < inLength; j++)
    {
        if (inData[j] == SOM_EOM)
        {
            *(outData + k) = ESC;
            k++;
            *(outData + k) = SOM_EOM_PLACEHOLDER;
            k++;
        }
        else if (inData[j] == ESC)
        {
            *(outData + k) = ESC;
            k++;
            *(outData + k) = ESC_PLACEHOLDER;
            k++;
        }
        else
        {
            *(outData + k) = inData[j];
            k++;
        }
    }

    *(outData + (totalCharsNeeded - 1)) = SOM_EOM;

    return totalCharsNeeded;
}

void spTxDataBack(const uint8_t* inData,
                            uint16_t inLength)
{
    uint16_t outLength;
    uint8_t outData[128];

    outLength = spFrameData(inData, inLength, outData);

    Serial.write(outData, outLength);
}

void spTxDataWait(const uint8_t* inData,
                            uint16_t inLength)
{
    uint16_t outLength;
    uint8_t outData[128];

    outLength = spFrameData(inData, inLength, outData);

    Serial.write(outData, outLength);
}
