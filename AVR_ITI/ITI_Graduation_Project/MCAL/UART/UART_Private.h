/*
 * UART_praiver.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef MCAL_UART_UART_PRAIVER_H_
#define MCAL_UART_UART_PRAIVER_H_

#include "../../LIB/BIT_MATH.h"       // Include bitwise operations
#include "../../LIB/STD_TYPES.h"      // Include standard types

/* USART Baud Rate Register Low */
#define UBRRL    	(*(volatile u8*)0x29)   // USART Baud Rate Register Low (8 bits)

/* USART Baud Rate Register High */
#define UBRRH    	(*(volatile u8*)0x40)   // USART Baud Rate Register High (8 bits)

/* USART Control and Status Register B */
#define UCSRB   	(*(volatile u8*)0x2A)   // USART Control and Status Register B (8 bits)

#define    RXCIE        7      // RX Complete Interrupt Enable
#define    TXCIE        6      // TX Complete Interrupt Enable
#define    UDRIE        5      // USART Data Register Empty Interrupt Enable
#define    RXEN         4      // Receiver Enable
#define    TXEN         3      // Transmitter Enable
#define    UCSZ         2      // Character Size (shared with UCSZ2)
#define    UCSZ2        2      // Character Size bit 2
#define    RXB8         1      // Receive Data Bit 8 (in 9-bit data mode)
#define    TXB8         0      // Transmit Data Bit 8 (in 9-bit data mode)

/* USART Control and Status Register A */
#define UCSRA    	(*(volatile u8*)0x2B)   // USART Control and Status Register A (8 bits)

#define    RXC          7      // RX Complete
#define    TXC          6      // TX Complete
#define    UDRE         5      // Data Register Empty
#define    FE           4      // Frame Error
#define    DOR          3      // Data OverRun
#define    UPE          2      // Parity Error
#define    U2X          1      // Double the USART Transmission Speed
#define    MPCM         0      // Multi-processor Communication Mode

/* USART I/O Data Register */
#define UDR       	(*(volatile u8*)0x2C)   // USART I/O Data Register (8 bits)

/* USART Control and Status Register C */
#define UCSRC     	(*(volatile u8*)0x40)   // USART Control and Status Register C (8 bits)

/* USART Register C Bit Fields */
#define    URSEL        7      // Register Select (1 = UCSRC, 0 = UBRRH)
#define    UMSEL        6      // USART Mode Select (1 = Synchronous, 0 = Asynchronous)
#define    UPM1         5      // Parity Mode bit 1
#define    UPM0         4      // Parity Mode bit 0
#define    USBS         3      // Stop Bit Select (1 = 2 stop bits, 0 = 1 stop bit)
#define    UCSZ1        2      // Character Size bit 1
#define    UCSZ0        1      // Character Size bit 0
#define    UCPOL        0      // Clock Polarity (Synchronous mode only)

#endif /* MCAL_UART_UART_PRAIVER_H_ */
