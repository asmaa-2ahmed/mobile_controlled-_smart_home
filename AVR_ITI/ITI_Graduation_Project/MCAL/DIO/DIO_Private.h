/*
 * DIO_Private.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file contains the private definitions for the Digital Input/Output (DIO) module.
 * It defines the memory-mapped I/O addresses for the DIO registers of the microcontroller.
 * These macros allow direct access to the DIO registers for reading and writing operations.
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_  // Include guard to prevent multiple inclusions of the header file
#define MCAL_DIO_DIO_PRIVATE_H_

// Definitions for Port A registers
#define PORTA   (*(volatile u8*)0x3B)   // Data Register for Port A
#define DDRA    (*(volatile u8*)0x3A)   // Data Direction Register for Port A
#define PINA    (*(volatile u8*)0x39)   // Input Pins Address for Port A

// Definitions for Port B registers
#define PORTB   (*(volatile u8*)0x38)   // Data Register for Port B
#define DDRB    (*(volatile u8*)0x37)   // Data Direction Register for Port B
#define PINB    (*(volatile u8*)0x36)   // Input Pins Address for Port B

// Definitions for Port C registers
#define PORTC   (*(volatile u8*)0x35)   // Data Register for Port C
#define DDRC    (*(volatile u8*)0x34)   // Data Direction Register for Port C
#define PINC    (*(volatile u8*)0x33)   // Input Pins Address for Port C

// Definitions for Port D registers
#define PORTD   (*(volatile u8*)0x32)   // Data Register for Port D
#define DDRD    (*(volatile u8*)0x31)   // Data Direction Register for Port D
#define PIND    (*(volatile u8*)0x30)   // Input Pins Address for Port D

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
