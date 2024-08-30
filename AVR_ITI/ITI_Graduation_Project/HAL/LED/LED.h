/*
 * LED.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file provides the interface for controlling an LED connected to a microcontroller.
 * It includes functions for initializing the LED, turning it on or off, toggling its state,
 * and reading its current status.
 */

#ifndef HAL__LED_LED_H_
#define HAL__LED_LED_H_

// Include Libraries
#include "../../LIB/STD_TYPES.h"        // Include standard types
#include "../../LIB/BIT_MATH.h"         // Include bitwise operations

#include "../../MCAL/DIO/DIO_Interface.h" // Include DIO interface functions
#include "../../MCAL/DIO/DIO_Config.h"    // Include DIO configuration settings

// Define constants for pin direction and state
#define OUTPUT 1   // Pin set as output
#define INPUT  0   // Pin set as input
#define HIGH   1   // Pin set to high state
#define LOW    0   // Pin set to low state

/**
 * @brief Initialize the LED by setting the direction of the specified pin.
 *
 * @param portname (IN) The port to which the LED is connected (e.g., PORT_A).
 * @param pinnumber (IN) The pin number to which the LED is connected (e.g., PIN0).
 *
 * @return void
 */
void LED_vInit(u8 portname, u8 pinnumber);

/**
 * @brief Turn on the LED by setting the specified pin to a high state.
 *
 * @param portname (IN) The port to which the LED is connected (e.g., PORT_A).
 * @param pinnumber (IN) The pin number to which the LED is connected (e.g., PIN0).
 *
 * @return void
 */
void LED_vTurnOn(u8 portname, u8 pinnumber);

/**
 * @brief Turn off the LED by setting the specified pin to a low state.
 *
 * @param portname (IN) The port to which the LED is connected (e.g., PORT_A).
 * @param pinnumber (IN) The pin number to which the LED is connected (e.g., PIN0).
 *
 * @return void
 */
void LED_vTurnOff(u8 portname, u8 pinnumber);

/**
 * @brief Toggle the LED state by inverting the current state of the specified pin.
 *
 * @param portname (IN) The port to which the LED is connected (e.g., PORT_A).
 * @param pinnumber (IN) The pin number to which the LED is connected (e.g., PIN0).
 *
 * @return void
 */
void LED_vToggle(u8 portname, u8 pinnumber);

/**
 * @brief Read the current status of the LED (on or off).
 *
 * @param portname (IN) The port to which the LED is connected (e.g., PORT_A).
 * @param pinnumber (IN) The pin number to which the LED is connected (e.g., PIN0).
 *
 * @return u8 (OUT) The current status of the LED: HIGH (on) or LOW (off).
 */
u8 LED_u8ReadStatus(u8 portname, u8 pinnumber);

#endif /* HAL__LED_LED_H_ */
