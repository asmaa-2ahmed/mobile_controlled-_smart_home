/*
 * Solenoid_Config.h
 *
 * Created on: Aug 18, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef HAL_SOLENOID_SOLENOID_CONFIG_H_
#define HAL_SOLENOID_SOLENOID_CONFIG_H_

/* Define the port and pin used for controlling the solenoid */
#define SOLO_PORT    PORT_B     // Port where the solenoid is connected
#define SOLO_PIN     PIN_0     // Pin where the solenoid is connected

/* Define the state of the solenoid control signal */
/* HIGH - Activate the solenoid */
/* LOW  - Deactivate the solenoid */
#define SOLO_ACTIVE_STATE    HIGH   // Define the active state for the solenoid
#define SOLO_INACTIVE_STATE  LOW    // Define the inactive state for the solenoid


#endif /* HAL_SOLENOID_SOLENOID_CONFIG_H_ */
