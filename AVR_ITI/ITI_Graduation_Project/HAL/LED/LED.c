/*
 * LED.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 */

#include "LED.h"

/**
 * @brief Initialize the LED pin.
 *
 * This function sets the direction of the specified pin as output
 * to control an LED.
 *
 * @param portname [in] The port where the LED is connected (e.g., PORT_A).
 * @param pinnumber [in] The pin number to which the LED is connected.
 * @return None (void).
 */
void LED_vInit(u8 portname, u8 pinnumber) {
    vSet_Pin_Direction(portname, pinnumber, OUTPUT);  // Set the LED pin as output
}

/**
 * @brief Turn on the LED.
 *
 * This function sets the specified pin to high to turn on the LED.
 *
 * @param portname [in] The port where the LED is connected.
 * @param pinnumber [in] The pin number to which the LED is connected.
 * @return None (void).
 */
void LED_vTurnOn(u8 portname, u8 pinnumber) {
    vSet_Pin_OUTPUTvalue(portname, pinnumber, HIGH);  // Set the pin to high
}

/**
 * @brief Turn off the LED.
 *
 * This function sets the specified pin to low to turn off the LED.
 *
 * @param portname [in] The port where the LED is connected.
 * @param pinnumber [in] The pin number to which the LED is connected.
 * @return None (void).
 */
void LED_vTurnOff(u8 portname, u8 pinnumber) {
    vSet_Pin_OUTPUTvalue(portname, pinnumber, LOW);  // Set the pin to low
}

/**
 * @brief Toggle the LED state.
 *
 * This function toggles the current state of the LED, turning it
 * on if it's off, and off if it's on.
 *
 * @param portname [in] The port where the LED is connected.
 * @param pinnumber [in] The pin number to which the LED is connected.
 * @return None (void).
 */
void LED_vToggle(u8 portname, u8 pinnumber) {
    vTOGGLE_Pin(portname, pinnumber);  // Toggle the LED state
}

/**
 * @brief Read the current status of the LED.
 *
 * This function returns the current state of the LED (on or off)
 * by reading the value of the pin to which the LED is connected.
 *
 * @param portname [in] The port where the LED is connected.
 * @param pinnumber [in] The pin number to which the LED is connected.
 * @return u8 [out] The current state of the LED (1 for on, 0 for off).
 */
u8 LED_u8ReadStatus(u8 portname, u8 pinnumber) {
    return vGIT_PIN(portname, pinnumber);  // Return the LED status
}
