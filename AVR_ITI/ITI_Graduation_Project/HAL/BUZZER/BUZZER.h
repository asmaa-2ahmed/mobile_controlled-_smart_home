/*
 * BUZZER.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_


// Include Libraries
#include "../../LIB/STD_TYPES.h"        // Include standard types
#include "../../LIB/BIT_MATH.h"         // Include bitwise operations

#include "../../MCAL/DIO/DIO_Interface.h" // Include DIO interface functions
#include "../../MCAL/DIO/DIO_Config.h"    // Include DIO configuration settings

#include <util/delay.h>              // Include delay utilities



// Define the port and pin for the buzzer
#define BUZZER_PORT   PORT_A    // Port where the buzzer is connected
#define BUZZER_PIN    PIN_7     // Pin number where the buzzer is connected





/**
 * @brief Initialize the buzzer pin
 *
 * This function sets up the buzzer pin as an output to control the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vInit(void);

/**
 * @brief Turn the buzzer on
 *
 * This function sets the buzzer pin to high, activating the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vTurnOn(void);

/**
 * @brief Turn the buzzer off
 *
 * This function sets the buzzer pin to low, deactivating the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vTurnOff(void);

/**
 * @brief Activate the siren alarm
 *
 * This function generates a siren-like sound by toggling the buzzer on and off
 * in a specific pattern.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vSirenAlarm(void);

#endif /* HAL_BUZZER_BUZZER_H_ */
