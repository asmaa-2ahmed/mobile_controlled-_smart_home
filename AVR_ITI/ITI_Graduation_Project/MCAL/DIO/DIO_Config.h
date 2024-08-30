/*
 * DIO_Config.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file contains configuration definitions for the Digital Input/Output (DIO) module.
 * It defines macros for port IDs, pin IDs, direction settings, and pin output statuses.
 * These macros are used to configure and control the microcontroller's digital I/O operations.
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_  // Include guard to prevent multiple inclusions of the header file
#define MCAL_DIO_DIO_CONFIG_H_

/********************* PORT ID ***************************/
#define PORT_A        0  // Identifier for Port A
#define PORT_B        1  // Identifier for Port B
#define PORT_C        2  // Identifier for Port C
#define PORT_D        3  // Identifier for Port D

/******************** PIN ID *************************/
#define PIN_0         0  // Identifier for Pin 0
#define PIN_1         1  // Identifier for Pin 1
#define PIN_2         2  // Identifier for Pin 2
#define PIN_3         3  // Identifier for Pin 3
#define PIN_4         4  // Identifier for Pin 4
#define PIN_5         5  // Identifier for Pin 5
#define PIN_6         6  // Identifier for Pin 6
#define PIN_7         7  // Identifier for Pin 7

/******************* DIRECTION ****************************/
#define OUTPUT        1  // Macro to set pin direction as output
#define INPUT         0  // Macro to set pin direction as input

/**************** PIN OUTPUT STATUS ****************/
#define HIGH          1  // Macro to set pin output to high
#define LOW           0  // Macro to set pin output to low

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
