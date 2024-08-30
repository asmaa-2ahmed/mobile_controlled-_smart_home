/*
 * BLUETOOTH.c
 *
 * Created on: Aug 16, 2024
 * Author: Arwa Mekawy
 */

//#include "../../LIB/STD_TYPES.h"        // Include standard types
//#include "../../LIB/BIT_MATH.h"         // Include bitwise operations
//
//#include "../../MCAL/DIO/DIO_Interface.h" // Include DIO interface functions
//#include "../../MCAL/DIO/DIO_Config.h"    // Include DIO configuration settings
//#include "../../MCAL/UART/UART_Interface.h" // Ensure correct path and header
//#include "../../MCAL/UART/UART_Config.h
//
//#include "BLUETOOTH.h"

//// Function to initialize the Bluetooth module
//void Bluetooth_vInit() {
//    UART_Init();  // Initialize UART
//    UART_SetParity(PARITY); // Set parity
//    UART_SetStopBits(STOP_BITS); // Set stop bits
//    UART_SetDataBits(DATA_BITS); // Set data bits
//    UART_SetBaudRate(BOUD_RATE); // Set baud rate
//    UART_SetMode(OPERATION_MODE, SPEED_MODE); // Set mode and speed
//}
//
//// Function to enable the Bluetooth module
//void Bluetooth_vEnable() {
//    UART_EnableRx();  // Enable UART receiver
//    UART_EnableTx();  // Enable UART transmitter
//}
//
//// Function to disable the Bluetooth module
//void Bluetooth_vDisable() {
//    UART_DisableRx();  // Disable UART receiver
//    UART_DisableTx();  // Disable UART transmitter
//}
//
//// Function to send a single byte of data via Bluetooth
//void Bluetooth_vSendData(u8 data) {
//    UART_TransmitData(data);  // Send data byte using UART
//}
//
//// Function to receive a single byte of data from Bluetooth
//u8 Bluetooth_u8ReceiveData(void) {
//    return UART_ReceiveByte();  // Receive data byte using UART
//}
//
//// Function to send a string of data via Bluetooth
//void Bluetooth_vSendString(const char* str) {
//    UART_TransmitString(str);  // Send each byte of the string using UART
//}
//
//// Function to clear the Bluetooth receive buffer
//void Bluetooth_vClearBuffer() {
//    char dummy; // Temporary variable to hold discarded data
//    while (GET_BIT(UCSRA, RXC)) { // Ensure UCSRA and RXC are defined
//        dummy = UART_ReceiveByte();  // Read and discard bytes in the buffer
//    }
//}
