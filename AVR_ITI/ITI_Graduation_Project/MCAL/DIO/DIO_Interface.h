/*
 * DIO_Interface.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file provides the interface for the Digital Input/Output (DIO) module.
 * It contains the function prototypes that allow users to interact with the DIO functions
 * to set pin directions, control pin output values, and read pin states, among other operations.
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_  // Include guard to prevent multiple inclusions of the header file
#define MCAL_DIO_DIO_INTERFACE_H_


// Include Libraries
#include "../../LIB/STD_TYPES.h"  // Include standard data types
#include "../../LIB/BIT_MATH.h"    // Include bit manipulation macros

#include "DIO_Config.h"            // Include DIO configuration settings
#include "DIO_Private.h"           // Include private definitions for DIO


#define HIGH 1
#define LOW 0

//*************** FUNCTION PROTOTYPES *************************

/**
 * @brief Set the direction of a specific pin.
 *
 * @param PORT_ID  (IN)  Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID   (IN)  Pin number to be set (e.g., PIN0).
 * @param Direction (IN) The direction of the pin (INPUT or OUTPUT).
 *
 * @return void
 */
void vSet_Pin_Direction(u8 PORT_ID , u8 PIN_ID , u8 Direction);

/**
 * @brief Set the output value of a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID (IN) Pin number to be set (e.g., PIN0).
 * @param Value (IN) The value to be set (HIGH or LOW).
 *
 * @return void
 */
void vSet_Pin_OUTPUTvalue(u8 PORT_ID , u8 PIN_ID , u8 Value);

/**
 * @brief Toggle the output value of a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID (IN) Pin number to be toggled (e.g., PIN0).
 *
 * @return void
 */
void vTOGGLE_Pin(u8 PORT_ID , u8 PIN_ID);

/**
 * @brief Get the input value of a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID (IN) Pin number to read (e.g., PIN0).
 *
 * @return u8 (OUT) The current input value of the pin (HIGH or LOW).
 */
u8 vGIT_PIN(u8 PORT_ID , u8 PIN_ID);

/**
 * @brief Set the direction of all pins in a specific port.
 *
 * @param PORT_ID (IN) Port ID to set the direction for (e.g., PORT_A).
 * @param Direction (IN) The direction for all pins (INPUT or OUTPUT).
 *
 * @return void
 */
void vSet_Port_Direction(u8 PORT_ID , u8 Direction);

/**
 * @brief Set the output value for all pins in a specific port.
 *
 * @param PORT_ID (IN) Port ID to set the output value for (e.g., PORT_A).
 * @param Value (IN) The value to be set for all pins (HIGH or LOW).
 *
 * @return void
 */
void vSet_Port_OUTPUTvalue(u8 PORT_ID , u8 Value);

/**
 * @brief Toggle the output value of all pins in a specific port.
 *
 * @param PORT_ID (IN) Port ID to toggle the value for (e.g., PORT_A).
 *
 * @return void
 */
void vTOGGLE_port(u8 PORT_ID);

/**
 * @brief Enable the internal pull-up resistor for a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID (IN) Pin number to enable pull-up (e.g., PIN0).
 *
 * @return void
 */
void vSetInernalPullUp(u8 PORT_ID , u8 PIN_ID);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
