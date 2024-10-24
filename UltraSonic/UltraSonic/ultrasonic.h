 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the ULTRASONIC driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "gpio.h"
#include "icu.h"

extern Icu_ConfigType Icu_Config;
extern void Ultrasonic_edgeProcessing(void);

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TRIGGER_PORT_ID		PORTB_ID
#define	TRIGGER_PIN_ID		PIN5_ID
#define ECHO_PORT_ID		PORTD_ID
#define ECHO_PIN_ID			PIN6_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description
 * Initialize the ICU driver as required.
 * Setup the ICU call back function.
 * Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void);

/*
 * Description
 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void);

/*Description
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void);


#endif /* ULTRASONIC_H_ */
