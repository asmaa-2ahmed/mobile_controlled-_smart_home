/*
 * SmartHome_Interface.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef APP_SMART_HOME_SMARTHOME_INTERFACE_H_
#define APP_SMART_HOME_SMARTHOME_INTERFACE_H_

// Include Libraries

#include "../LIB/STD_TYPES.h" // Include standard types for the data types used

#include "../MCAL/DIO/DIO_Config.h"  // Include configuration settings for DIO (Digital I/O)
#include "../MCAL/DIO/DIO_Interface.h" // Include DIO interface functions for handling pin operations
#include "../MCAL/DIO/DIO_Private.h"  // Include private definitions for DIO, possibly including low-level details

#include "../MCAL/UART/UART_Config.h"  // Include configuration settings for UART (Universal Asynchronous Receiver-Transmitter)
#include "../MCAL/UART/UART_Interface.h" // Include UART interface functions for serial communication
#include "../MCAL/UART/UART_Private.h"  // Include private definitions for UART, possibly including low-level details

#include "../MCAL/TIMERS/TIMER_Config.h" // Include configuration settings for Timers
#include "../MCAL/TIMERS/TIMER_Interface.h" // Include Timer interface functions for managing timer operations
#include "../MCAL/TIMERS/TIMER_Private.h"  // Include private definitions for Timer, possibly including low-level details

#include <string.h> // Include string manipulation functions
#include <util/delay.h> // Include delay functions from AVR library

// Pin Definitions for Hardware Components
#define LED_PIN           PIN_0    // Pin for LED control
#define BUZZER_PIN        PIN_1    // Pin for Buzzer control
#define DOOR_PIN          PIN_5    // Pin for Door control

// Constants for System Limits
#define MAX_USERS         10      // Maximum number of users allowed
#define MAX_TRIALS        3       // Maximum number of authentication trials allowed
#define MAX_LENGTH        20      // Maximum length for string inputs

// Constants for Door Control
#define OPEN              1       // Command to open the door
#define CLOSE             2       // Command to close the door

/**
 * @brief Initializes the smart home system.
 *
 * This function sets up the necessary hardware and software components
 * for the smart home system to operate correctly. It configures the pin
 * directions and initializes communication protocols.
 *
 * @param None
 * @return void
 */
void SMART_INIT(void);

/**
 * @brief Performs authentication of a user.
 *
 * This function handles the authentication process, checking if the user
 * input matches stored credentials. It allows a specified number of attempts
 * before activating a buzzer to indicate failure.
 *
 * @param None
 * @return int (OUT) - Status code representing the result of the authentication:
 *                      0: Authentication failed
 *                      1: Authentication succeeded
 */
int AUTHENTICATION(void);

/**
 * @brief Controls the LED based on the provided order.
 *
 * This function turns the LED on or off based on the specified order.
 * The order parameter determines the action to be taken.
 *
 * @param order (IN) - The command to control the LED. This could be:
 *                     '1' to turn the LED ON
 *                     '2' to turn the LED OFF
 * @return void
 */
void LED_CONTROL(u8 order);

/**
 * @brief Sets the state of the door (open or close).
 *
 * This function controls the state of the door by sending the appropriate
 * command to open or close it. The command is used to operate the door lock.
 *
 * @param state (IN) - The desired state of the door:
 *                     OPEN (1): Open the door
 *                     CLOSE (2): Close the door
 * @return void
 */
void DOOR_CONTROL(u8 state);

/**
 * @brief Sets the angle of the servo motor.
 *
 * This function adjusts the position of the servo motor to a specified angle.
 * The angle is typically in the range of 0 to 180 degrees.
 *
 * @param angle (IN) - The angle to set the servo motor to, typically ranging
 *                     from 0 to 180 degrees.
 * @return void
 */
void servo_angle(u8 angle);

#endif /* APP_SMART_HOME_SMARTHOME_INTERFACE_H_ */
