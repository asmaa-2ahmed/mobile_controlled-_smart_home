/*
 * Solenoid_Interface.h
 *
 * Created on: Aug 19, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef HAL_SOLENOID_SOLENOID_INTERFACE_H_
#define HAL_SOLENOID_SOLENOID_INTERFACE_H_

// Include Libraries
#include "../../LIB/STD_TYPES.h"        // Include standard types
#include "../../LIB/BIT_MATH.h"         // Include bitwise operations

#include "../../MCAL/DIO/DIO_Interface.h" // Include DIO interface functions
#include "../../MCAL/DIO/DIO_Config.h"    // Include DIO configuration settings
#include "Solenoid_Private.h"
#include "Solenoid_Config.h" // Include the configuration file


/**
 * @brief Initializes the solenoid control system.
 *
 * This function sets up the pin connected to the solenoid as OUTPUT.
 *
 * @param None
 * @return void
 */
void Solenoid_Init(void);

/**
 * @brief Activates the solenoid.
 *
 * This function turns the solenoid ON by setting the corresponding pin HIGH.
 *
 * @param None
 * @return void
 */
void Solenoid_Activate(void);

/**
 * @brief Deactivates the solenoid.
 *
 * This function turns the solenoid OFF by setting the corresponding pin LOW.
 *
 * @param None
 * @return void
 */
void Solenoid_Deactivate(void);

#endif /* HAL_SOLENOID_SOLENOID_INTERFACE_H_ */
