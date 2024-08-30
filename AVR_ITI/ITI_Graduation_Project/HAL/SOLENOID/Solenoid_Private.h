/*
 * Solenoid_Private.h
 *
 * Created on: Aug 18, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef HAL_SOLENOID_SOLENOID_PRIVATE_H_
#define HAL_SOLENOID_SOLENOID_PRIVATE_H_

/* Private Macros */

/* Define solenoid activation and deactivation times (in milliseconds) */
#define SOLO_ACTIVATION_TIME_MS 1000   // Time to keep the solenoid activated
#define SOLO_DEACTIVATION_TIME_MS 1000 // Time to keep the solenoid deactivated

/* Define solenoid status */
#define SOLO_STATUS_ACTIVE    1 // Solenoid is currently active
#define SOLO_STATUS_INACTIVE  0 // Solenoid is currently inactive

/* Private Constants */

/* Example constants for solenoid operation */
/* These constants could be adjusted based on specific requirements or hardware setup */

/* Define error codes for solenoid operations */
#define SOLO_ERROR_NONE       0   // No error
#define SOLO_ERROR_TIMEOUT    1   // Timeout error
#define SOLO_ERROR_UNKNOWN    2   // Unknown error

#endif /* HAL_SOLENOID_SOLENOID_PRIVATE_H_ */
