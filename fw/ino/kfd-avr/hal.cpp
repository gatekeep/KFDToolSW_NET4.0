#include "hal.h"

void(* resetFunc) (void) = 0;

void halInit(void)
{

    // ACT_LED
    pinMode(ACTIVITY_LED_PIN, OUTPUT);
    digitalWrite(ACTIVITY_LED_PIN, LOW);

    // SNS_LED
    pinMode(SENSE_LED_PIN, OUTPUT);
    digitalWrite(SENSE_LED_PIN, LOW);

    // MCU_DATA_OUT_3V3
    pinMode(DATA_TX, OUTPUT);
    digitalWrite(DATA_TX, LOW);

    // MCU_DATA_IN_3V3
    pinMode(DATA_RX, INPUT);
    // make it an interrupt later

    // MCU_SENSE_OUT_3V3
    pinMode(SNS_TX, OUTPUT);
    digitalWrite(SNS_TX, LOW);

    // MCU_SENSE_IN_3V3
    pinMode(SNS_RX, INPUT);

    // GPIO1
    pinMode(GPIO1, OUTPUT);
    digitalWrite(GPIO1, LOW);

    // GPIO2
    pinMode(GPIO2, OUTPUT);
    digitalWrite(GPIO2, LOW);

    // UP_BUTTON
    pinMode(UP_BUTTON_PIN, INPUT);

    // DOWN_BUTTON
    pinMode(DOWN_BUTTON_PIN, INPUT);

    // ENTER_BUTTON
    pinMode(ENTER_BUTTON_PIN, INPUT);   

    // blink the LEDs
    for (int i=0; i<3; i++)
    {
        halActLedOn();
        halSnsLedOn();
        halDelayMs(250);
        halActLedOff();
        halSnsLedOff();
        halDelayMs(250);
    }

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

/**
 * BEGIN LED macros
 */

void halActLedOn(void)
{
    digitalWrite(ACTIVITY_LED_PIN, HIGH);
}

void halActLedOff(void)
{
    digitalWrite(ACTIVITY_LED_PIN, LOW);
}

void halActLedToggle(void)
{
    digitalWrite(ACTIVITY_LED_PIN, !digitalRead(ACTIVITY_LED_PIN));
}

void halSnsLedOn(void)
{
    digitalWrite(SENSE_LED_PIN, HIGH);
}

void halSnsLedOff(void)
{
    digitalWrite(SENSE_LED_PIN, LOW);
}

void halSnsLedToggle(void)
{
    digitalWrite(SENSE_LED_PIN, !digitalRead(SENSE_LED_PIN));
}

/**
 * END LED macros
 */

/**
 * BEGIN GPIO macros
 */
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

/**
 * END GPIO macros
 */

/**
 * BEGIN KFD macros
 */

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

/**
 * END KFD macros
 */

/**
 * BEGIN BUTTON macros
 */

#define BUTTON_UP_PRESSED digitalRead(UP_BUTTON_PIN) == 0
#define BUTTON_UP_RELEASED digitalRead(UP_BUTTON_PIN) == 1

#define BUTTON_DOWN_PRESSED digitalRead(DOWN_BUTTON_PIN) == 0
#define BUTTON_DOWN_RELEASED digitalRead(DOWN_BUTTON_PIN) == 1

#define BUTTON_ENTER_PRESSED digitalRead(ENTER_BUTTON_PIN) == 0
#define BUTTON_ENTER_RELEASED digitalRead(ENTER_BUTTON_PIN) == 1

/**
 * END BUTTON macros
 */