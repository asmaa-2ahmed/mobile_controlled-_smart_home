/*
 * DIO_Program.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This source file contains the implementation of functions related to Digital Input/Output (DIO)
 * operations for a microcontroller. These functions allow for setting pin directions, setting and
 * toggling output values, and reading pin states. The functions are designed to work with different
 * ports and pins of the microcontroller.
 */

#include "DIO_Interface.h"         // Include DIO interface declarations
/**
 * @brief Set the direction of a specific pin (input or output).
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID  (IN) Pin number to be set (e.g., PIN0).
 * @param Direction (IN) The direction of the pin (INPUT or OUTPUT).
 *
 * @return void
 */
void vSet_Pin_Direction(u8 PORT_ID , u8 PIN_ID , u8 Direction)
{
	switch(Direction)
	{
	case OUTPUT: // Set pin as output
		switch(PORT_ID)
		{
		case PORT_A: SET_BIT(DDRA, PIN_ID); break;
		case PORT_B: SET_BIT(DDRB, PIN_ID); break;
		case PORT_C: SET_BIT(DDRC, PIN_ID); break;
		case PORT_D: SET_BIT(DDRD, PIN_ID); break;
		}
		break;

	case INPUT: // Set pin as input
		switch(PORT_ID)
		{
		case PORT_A: CLEAR_BIT(DDRA, PIN_ID); break;
		case PORT_B: CLEAR_BIT(DDRB, PIN_ID); break;
		case PORT_C: CLEAR_BIT(DDRC, PIN_ID); break;
		case PORT_D: CLEAR_BIT(DDRD, PIN_ID); break;
		}
		break;
	}
}

/**
 * @brief Set the output value of a specific pin (high or low).
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID  (IN) Pin number to be set (e.g., PIN0).
 * @param Value   (IN) The value to be set (HIGH or LOW).
 *
 * @return void
 */
void vSet_Pin_OUTPUTvalue(u8 PORT_ID , u8 PIN_ID , u8 Value)
{
	switch(Value)
	{
	case HIGH: // Set pin output to high
		switch(PORT_ID)
		{
		case PORT_A: SET_BIT(PORTA, PIN_ID); break;
		case PORT_B: SET_BIT(PORTB, PIN_ID); break;
		case PORT_C: SET_BIT(PORTC, PIN_ID); break;
		case PORT_D: SET_BIT(PORTD, PIN_ID); break;
		}
		break;

	case LOW: // Set pin output to low
		switch(PORT_ID)
		{
		case PORT_A: CLEAR_BIT(PORTA, PIN_ID); break;
		case PORT_B: CLEAR_BIT(PORTB, PIN_ID); break;
		case PORT_C: CLEAR_BIT(PORTC, PIN_ID); break;
		case PORT_D: CLEAR_BIT(PORTD, PIN_ID); break;
		}
		break;
	}
}

/**
 * @brief Toggle the output value of a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID  (IN) Pin number to be toggled (e.g., PIN0).
 *
 * @return void
 */
void vTOGGLE_Pin(u8 PORT_ID , u8 PIN_ID)
{
	switch(PORT_ID)
	{
	case PORT_A: TOG_BIT(PORTA, PIN_ID); break;
	case PORT_B: TOG_BIT(PORTB, PIN_ID); break;
	case PORT_C: TOG_BIT(PORTC, PIN_ID); break;
	case PORT_D: TOG_BIT(PORTD, PIN_ID); break;
	}
}

/**
 * @brief Set the direction of all pins in a specific port (input or output).
 *
 * @param PORT_ID  (IN) Port ID to set the direction for (e.g., PORT_A).
 * @param Direction (IN) The direction for all pins (INPUT or OUTPUT).
 *
 * @return void
 */
void vSet_Port_Direction(u8 PORT_ID , u8 Direction)
{
	switch(Direction)
	{
	case OUTPUT: // Set entire port as output
		switch(PORT_ID)
		{
		case PORT_A: DDRA = 0xff; break;
		case PORT_B: DDRB = 0xff; break;
		case PORT_C: DDRC = 0xff; break;
		case PORT_D: DDRD = 0xff; break;
		}
		break;

	case INPUT: // Set entire port as input
		switch(PORT_ID)
		{
		case PORT_A: DDRA = 0x00; break;
		case PORT_B: DDRB = 0x00; break;
		case PORT_C: DDRC = 0x00; break;
		case PORT_D: DDRD = 0x00; break;
		}
		break;
	}
}

/**
 * @brief Set the output value for all pins in a specific port.
 *
 * @param PORT_ID (IN) Port ID to set the output value for (e.g., PORT_A).
 * @param Value   (IN) The value to be set for all pins (HIGH or LOW).
 *
 * @return void
 */
void vSet_Port_OUTPUTvalue(u8 PORT_ID , u8 Value)
{
	switch(PORT_ID)
	{
	case PORT_A: PORTA = Value; break;
	case PORT_B: PORTB = Value; break;
	case PORT_C: PORTC = Value; break;
	case PORT_D: PORTD = Value; break;
	}
}

/**
 * @brief Get the input value of a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID  (IN) Pin number to read (e.g., PIN0).
 *
 * @return u8 (OUT) The current input value of the pin (HIGH or LOW).
 */
u8 vGIT_PIN(u8 PORT_ID , u8 PIN_ID)
{
	u8 BIT = 0;
	switch(PORT_ID)
	{
	case PORT_A: BIT = GET_BIT(PINA, PIN_ID); break;
	case PORT_B: BIT = GET_BIT(PINB, PIN_ID); break;
	case PORT_C: BIT = GET_BIT(PINC, PIN_ID); break;
	case PORT_D: BIT = GET_BIT(PIND, PIN_ID); break;
	}
	return BIT; // Return the status of the specific pin
}

/**
 * @brief Enable the internal pull-up resistor for a specific pin.
 *
 * @param PORT_ID (IN) Port ID where the pin is located (e.g., PORT_A).
 * @param PIN_ID  (IN) Pin number to enable pull-up (e.g., PIN0).
 *
 * @return void
 */
void vSetInernalPullUp(u8 PORT_ID , u8 PIN_ID )
{
	vSet_Pin_OUTPUTvalue(PORT_ID, PIN_ID, HIGH);
}
