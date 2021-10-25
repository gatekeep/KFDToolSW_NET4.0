#ifndef HAL_H_
#define HAL_H_

#include <Arduino.h>

// 16MHz, as most avr arduinos are
#define FCPU 16000000

#define LED_PIN 13  // most arduinos have a light on pin 13
#define DATA_TX 5   // TWI Data TX
#define DATA_RX 3   // TWI Data RX (INT0)
#define SNS_TX 4    // TWI Sense TX
#define SNS_RX 2    // TWI Sense RX (INT1)
#define GPIO1 6
#define GPIO2 9

void halInit(void);

void halDelayUs(uint16_t us);

void halDelayMs(uint16_t ms);

void halEnterBsl(void);

void halReset(void);

void halLed1On(void);

void halLed1Off(void);

void halLed1Toggle(void);

void halGpio1High(void);

void halGpio1Low(void);

void halGpio1Toggle(void);

void halGpio2High(void);

void halGpio2Low(void);

void halGpio2Toggle(void);

void halKfdTxBusy(void);

void halKfdTxIdle(void);

void halSenTxConn(void);

void halSenTxDisc(void);

#endif /* HAL_H_ */
