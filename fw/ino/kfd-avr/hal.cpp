#include "hal.h"

void(* resetFunc) (void) = 0;

void halInit(void)
{

    // GPIO13 LED1
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // GPIO2 MCU_DATA_OUT_3V3
    pinMode(DATA_TX, OUTPUT);
    digitalWrite(DATA_TX, LOW);

    // P1.3 MCU_DATA_IN_3V3
    pinMode(DATA_RX, INPUT);
    // make it an interrupt later

    // P2.4 MCU_SENSE_OUT_3V3
    pinMode(SNS_TX, OUTPUT);
    digitalWrite(SNS_TX, LOW);

    // P2.5 MCU_SENSE_IN_3V3
    pinMode(SNS_RX, INPUT);

    // P4.4 GPIO1
    pinMode(GPIO1, OUTPUT);
    digitalWrite(GPIO1, LOW);

    // P4.5 GPIO2
    pinMode(GPIO2, OUTPUT);
    digitalWrite(GPIO2, LOW);

    // set all unused pins output low
}

void halDelayUs(uint16_t us)
{
    delayMicroseconds(us);
}

void halDelayMs(uint16_t ms)
{
    delay(ms);
}

void halEnterBsl(void)
{
    resetFunc();
}

void halReset(void)
{
    resetFunc();
}

void halLed1On(void)
{
    digitalWrite(LED_PIN, HIGH);
}

void halLed1Off(void)
{
    digitalWrite(LED_PIN, LOW);
}

void halLed1Toggle(void)
{
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

void halGpio1High(void)
{
    digitalWrite(GPIO1, HIGH);
}

void halGpio1Low(void)
{
    digitalWrite(GPIO1, LOW);
}

void halGpio1Toggle(void)
{
    digitalWrite(GPIO1, !digitalRead(GPIO1));
}

void halGpio2High(void)
{
    digitalWrite(GPIO2, HIGH);
}

void halGpio2Low(void)
{
    digitalWrite(GPIO2, LOW);
}

void halGpio2Toggle(void)
{
    digitalWrite(GPIO2, !digitalRead(GPIO2));
}

void halKfdTxBusy(void)
{
    digitalWrite(DATA_TX, HIGH);
}

void halKfdTxIdle(void)
{
    digitalWrite(DATA_TX, LOW);
}

void halSenTxConn(void)
{
    digitalWrite(SNS_TX, HIGH);
}

void halSenTxDisc(void)
{
    digitalWrite(SNS_TX, LOW);
}
