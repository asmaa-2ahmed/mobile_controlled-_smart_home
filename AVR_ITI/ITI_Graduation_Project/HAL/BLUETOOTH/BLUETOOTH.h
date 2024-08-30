///*
// * BLUETOOTH.h
// *
// * Created on: Aug 16, 2024
// * Author: Arwa Mekawy
// */
//
//#ifndef HAL_BLUETOOTH_BLUETOOTH_H_
//#define HAL_BLUETOOTH_BLUETOOTH_H_
//
//#include "../../LIB/STD_TYPES.h" // Include standard types
//
///**
// * @brief Initialize the Bluetooth module.
// *
// * This function sets up the Bluetooth module by configuring the necessary hardware
// * and initializing communication settings. This should be called before using any
// * other Bluetooth functions.
// *
// * (IN)  None.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vInit(void);
//
///**
// * @brief Enable the Bluetooth module.
// *
// * This function activates the Bluetooth module, allowing it to start communication.
// * It should be called to enable Bluetooth functionality after initialization.
// *
// * (IN)  None.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vEnable(void);
//
///**
// * @brief Disable the Bluetooth module.
// *
// * This function deactivates the Bluetooth module, stopping any ongoing communication
// * and conserving power. It should be called when Bluetooth communication is not needed.
// *
// * (IN)  None.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vDisable(void);
//
///**
// * @brief Send a single byte of data via Bluetooth.
// *
// * This function transmits a single byte of data to a paired Bluetooth device.
// *
// * @param Copy_u8Data The byte of data to be sent.
// * (IN)  Copy_u8Data: Data byte to send.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vSendData(u8 Copy_u8Data);
//
///**
// * @brief Receive a single byte of data from Bluetooth.
// *
// * This function reads a byte of data received from a paired Bluetooth device.
// *
// * (IN)  None.
// * (OUT) None.
// * @return The received byte of data.
// */
//u8 Bluetooth_u8ReceiveData(void);
//
///**
// * @brief Send a string of data via Bluetooth.
// *
// * This function transmits a null-terminated string of data to a paired Bluetooth device.
// *
// * @param Copy_u8Str Pointer to the string to be sent.
// * (IN)  Copy_u8Str: Pointer to the null-terminated string to send.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vSendString(u8 *Copy_u8Str);
//
///**
// * @brief Clear the Bluetooth receive buffer.
// *
// * This function clears any data present in the Bluetooth receive buffer to prepare
// * for new incoming data.
// *
// * (IN)  None.
// * (OUT) None.
// * @return void
// */
//void Bluetooth_vClearBuffer(void);
//
//#endif /* HAL_BLUETOOTH_BLUETOOTH_H_ */
