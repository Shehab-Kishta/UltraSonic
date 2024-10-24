/******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the ULTRASONIC driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#include "ultrasonic.h"
#include <util/delay.h>
#include "gpio.h"

extern uint8 g_counter;
extern uint16 g_upTime;

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/
/*
 * Description
 * Initialize the ICU driver as required.
 * Setup the ICU call back function.
 * Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void)
{
	Icu_init(&Icu_Config);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);
}

/*
 * Description
 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Description
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance = 0;
	Ultrasonic_Trigger();
	while(g_counter != 2);
	g_counter = 0;
	distance = (uint16)(g_upTime/58.8);
	return distance;
}
