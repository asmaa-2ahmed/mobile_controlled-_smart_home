/*
 * UART_int.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

// Include Libraries
#include "../../LIB/BIT_MATH.h"       // Include bitwise operations
#include "../../LIB/STD_TYPES.h"      // Include standard types
#include "UART_Config.h"
#include "UART_Private.h"
/* Parity Options */
#define NO_PARITY           0        // No parity bit
#define EVEN_PARITY         1        // Even parity
#define ODD_PARITY          2        // Odd parity

/* Stop Bits Options */
#define ONE_STOP_BIT        0        // Single stop bit
#define TWO_STOP_BIT        1        // Two stop bits

/* Data Bits Options */
#define DATA_BITS_5         0        // 5 data bits
#define DATA_BITS_6         1        // 6 data bits
#define DATA_BITS_7         2        // 7 data bits
#define DATA_BITS_8         3        // 8 data bits
#define DATA_BITS_9         4        // 9 data bits

/* Baud Rate Options */
/* In case of normal speed */
#define BAUD_9600_F_8       51       // Baud rate 9600 with normal speed
/* In case of double speed */
#define BAUD_9600_F_8_D     103      // Baud rate 9600 with double speed

/* Mode Options */
/* Synchronization */
#define UART_ASYNCH         0        // Asynchronous mode
#define UART_SYNCH          1        // Synchronous mode
/* Speed */
#define NORMAL_SPEED        0        // Normal speed
#define DOUBLE_SPEED        1        // Double speed

/* Function Prototypes */
void UART_TransmitString(const char* str);
u8 UART_ReceiveByte(void);

/**
 * @brief Initialize the UART module with the defined settings.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_Init(void);

/**
 * @brief Set the parity mode for UART communication.
 *
 * (IN)  parity: The parity mode to be set (NO_PARITY, EVEN_PARITY, ODD_PARITY).
 * (OUT) None.
 * @return void.
 */
void UART_SetParity(u8 parity);

/**
 * @brief Set the number of stop bits for UART communication.
 *
 * (IN)  noOfStopBits: The number of stop bits to be set (ONE_STOP_BIT, TWO_STOP_BIT).
 * (OUT) None.
 * @return void.
 */
void UART_SetStopBits(u8 noOfStopBits);

/**
 * @brief Set the number of data bits for UART communication.
 *
 * (IN)  noOfDataBits: The number of data bits to be set (DATA_BITS_5 to DATA_BITS_9).
 * (OUT) None.
 * @return void.
 */
void UART_SetDataBits(u8 noOfDataBits);

/**
 * @brief Set the baud rate for UART communication.
 *
 * (IN)  baud: The baud rate to be set.
 * (OUT) None.
 * @return void.
 */
void UART_SetBaudRate(u16 baud);

/**
 * @brief Set the mode (synchronous/asynchronous) and speed for UART communication.
 *
 * (IN)  synchMode: The synchronization mode (UART_ASYNCH or UART_SYNCH).
 * (IN)  speed: The speed mode (NORMAL_SPEED or DOUBLE_SPEED).
 * (OUT) None.
 * @return void.
 */
void UART_SetMode(u8 synchMode, u8 speed);

/**
 * @brief Transmit a single data byte via UART.
 *
 * (IN)  data: The data byte to be transmitted.
 * (OUT) None.
 * @return void.
 */
void UART_TransmitData(u16 data);

/**
 * @brief Transmit a null-terminated string via UART.
 *
 * (IN)  str: Pointer to the string to be transmitted.
 * (OUT) None.
 * @return void.
 */
void UART_TransmitString(const char* str);

/**
 * @brief Receive a single data byte via UART.
 *
 * (OUT) u16: The received data byte.
 */
u16 UART_ReceiveData(void);

/**
 * @brief Receive a string via UART until a termination character is encountered or the buffer is full.
 *
 * (IN)  buffer: Pointer to the buffer where the received string will be stored.
 * (IN)  maxLength: The maximum length of the string to be received.
 * (OUT) None.
 * @return void.
 */
void UART_ReceiveString(char* buffer, u8 maxLength);

/**
 * @brief Enable the UART transmitter.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_EnableTx(void);

/**
 * @brief Disable the UART transmitter.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_DisableTx(void);

/**
 * @brief Enable the UART receiver.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_EnableRx(void);

/**
 * @brief Disable the UART receiver.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_DisableRx(void);

/**
 * @brief Enable the UART transmit interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_EnableTxInterrupt(void);

/**
 * @brief Disable the UART transmit interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_DisableTxInterrupt(void);

/**
 * @brief Enable the UART receive interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_EnableRxInterrupt(void);

/**
 * @brief Disable the UART receive interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_DisableRxInterrupt(void);

/**
 * @brief Enable the UART data register empty interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_EnableDataEmptyInterrupt(void);

/**
 * @brief Disable the UART data register empty interrupt.
 *
 * (IN)  None.
 * (OUT) None.
 * @return void.
 */
void UART_DisableDataEmptyInterrupt(void);

#endif /* MCAL_UART_UART_INT_H_ */
