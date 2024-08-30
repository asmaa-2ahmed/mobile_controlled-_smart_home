/*
 * UART_prog.c
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#include "UART_Interface.h"
void UART_Init(void)
{
	/* 1- Set Baud Rate */
	UART_SetBaudRate(BOUD_RATE);

	/* 2- Set mode, data bits, parity, and stop bits */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	/* 3- Enable Transmitter */
	UART_EnableTx();

	/* 4- Enable Receiver */
	UART_EnableRx();

	/* 5- Disable all interrupts */
	UART_DisableTxInterrupt();
	UART_DisableRxInterrupt();
	UART_DisableDataEmptyInterrupt();
}

void UART_SetParity(u8 parity)
{
	switch(parity)
	{
		case NO_PARITY:
			CLEAR_BIT(UCSRC, UPM0);
			CLEAR_BIT(UCSRC, UPM1);
			break;
		case EVEN_PARITY:
			CLEAR_BIT(UCSRC, UPM0);
			SET_BIT(UCSRC, UPM1);
			break;
		case ODD_PARITY:
			SET_BIT(UCSRC, UPM0);
			SET_BIT(UCSRC, UPM1);
			break;
		default:
			/* error handling */
			break;
	}
}

void UART_SetStopBits(u8 noOfStopBits)
{
	switch(noOfStopBits)
	{
		case ONE_STOP_BIT:
			CLEAR_BIT(UCSRC, USBS);
			break;
		case TWO_STOP_BIT:
			SET_BIT(UCSRC, USBS);
			break;
		default:
			/* error handling */
			break;
	}
}

void UART_SetDataBits(u8 noOfDataBits)
{
	switch(noOfDataBits)
	{
		case DATA_BITS_5:
			/* code for 5 data bits */
			break;
		case DATA_BITS_6:
			/* code for 6 data bits */
			break;
		case DATA_BITS_7:
			/* code for 7 data bits */
			break;
		case DATA_BITS_8:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case DATA_BITS_9:
			/* code for 9 data bits */
			break;
		default:
			/* error handling */
			break;
	}
}

void UART_SetBaudRate(u16 baud)
{
	UBRRL = (u8) baud;
	if (baud > 255)
	{
		CLEAR_BIT(UCSRC, URSEL);
		UBRRH = (u8)(baud >> 8);
	}
}

void UART_SetMode(u8 synchMode, u8 speed)
{
	switch(speed)
	{
		case NORMAL_SPEED:
			CLEAR_BIT(UCSRA, U2X);
			break;
		case DOUBLE_SPEED:
			SET_BIT(UCSRA, U2X);
			break;
		default:
			/* error handling */
			break;
	}

	switch(synchMode)
	{
		case UART_ASYNCH:
			CLEAR_BIT(UCSRC, UMSEL);
			break;
		case UART_SYNCH:
			SET_BIT(UCSRC, UMSEL);
			break;
		default:
			/* error handling */
			break;
	}
}

void UART_TransmitData(u16 data)
{
	while(!GET_BIT(UCSRA, UDRE));  // Wait until the data register is empty
	UDR = data;

	if(DATA_BITS == DATA_BITS_9)
	{
		if(GET_BIT(data, 9) == 1)
		{
			SET_BIT(UCSRB, TXB8);
		}
		else
		{
			CLEAR_BIT(UCSRB, TXB8);
		}
	}
}

void UART_TransmitString(const char* str)
{
	while (*str)
	{
		UART_TransmitData(*str);
		str++;
	}
}

u16 UART_ReceiveData(void)
{
	u16 retData = 0;

	while(GET_BIT(UCSRA, RXC) == 0);  // Wait until data is received

	retData = UDR;

	// Handle 9-bit data mode if necessary
	// if (DATA_BITS == DATA_BITS_9) { ... }

	return retData;
}

void UART_ReceiveString(char* buffer, u8 maxLength)
{
	u8 i = 0;
	char receivedChar = '\0';

	// Receive characters until newline, carriage return, or buffer is full
	do {
		receivedChar = UART_ReceiveData();
		buffer[i] = receivedChar;
		i++;
	} while ((receivedChar != '\n') && (receivedChar != '\r') && (i < (maxLength - 1)));

	buffer[i-1] = '\0';  // Null-terminate the string
}

void UART_EnableTx(void)
{
    // Enable the UART transmitter
    // This sets the TXEN bit in UCSRB (USART Control and Status Register B)
    // Allowing the UART module to transmit data
    SET_BIT(UCSRB, TXEN);
}

void UART_DisableTx(void)
{
    // Disable the UART transmitter
    // This clears the TXEN bit in UCSRB (USART Control and Status Register B)
    // Preventing the UART module from transmitting data
    CLEAR_BIT(UCSRB, TXEN);
}

void UART_EnableRx(void)
{
    // Enable the UART receiver
    // This sets the RXEN bit in UCSRB (USART Control and Status Register B)
    // Allowing the UART module to receive data
    SET_BIT(UCSRB, RXEN);
}

void UART_DisableRx(void)
{
    // Disable the UART receiver
    // This clears the RXEN bit in UCSRB (USART Control and Status Register B)
    // Preventing the UART module from receiving data
    CLEAR_BIT(UCSRB, RXEN);
}

// Function to receive a byte via UART
u8 UART_ReceiveByte(void)
{
    // Wait for data to be received
    while (!(UCSRA & (1 << RXC)));

    // Get and return received data from the buffer
    return UDR;
}


void UART_EnableTxInterrupt(void)
{
	// Implementation of enabling TX interrupt
}

void UART_DisableTxInterrupt(void)
{
	// Implementation of disabling TX interrupt
}

void UART_EnableRxInterrupt(void)
{
	// Implementation of enabling RX interrupt
}

void UART_DisableRxInterrupt(void)
{
	// Implementation of disabling RX interrupt
}

void UART_EnableDataEmptyInterrupt(void)
{
	// Implementation of enabling Data Empty interrupt
}

void UART_DisableDataEmptyInterrupt(void)
{
	// Implementation of disabling Data Empty interrupt
}
