/*
 * TIMER_Interface.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

/**
 * @file TIMER_Interface.h
 * @brief Interface for Timer0 operations.
 *
 * This header file provides the declarations for Timer0 functions and configuration constants.
 * It includes initialization, start/stop operations, preload settings, interrupt control,
 * and PWM mode configuration.
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

// Include Libraries
#include "../../LIB/BIT_MATH.h" // Include bit manipulation macros
#include "../../LIB/STD_TYPES.h" // Include standard data types

#include "TIMER_Config.h" // Include Timer configuration settings
#include "TIMER_Private.h" // Include Timer private functions and macros

// Prescaler options for Timer0
#define TIMER0_SCALER_1        1   ///< Prescaler value of 1 (no division)
#define TIMER0_SCALER_8        2   ///< Prescaler value of 8
#define TIMER0_SCALER_64       3   ///< Prescaler value of 64
#define TIMER0_SCALER_256      4   ///< Prescaler value of 256
#define TIMER0_SCALER_1024     5   ///< Prescaler value of 1024
#define EXTERNAL_FALLING       6   ///< External clock source with falling edge trigger
#define EXTERNAL_RISING        7   ///< External clock source with rising edge trigger

// Timer0 operation modes
#define TIMER0_NORMAL_MODE         0   ///< Normal mode
#define TIMER0_PHASECORRECT_MODE   1   ///< Phase correct PWM mode
#define TIMER0_CTC_MODE            2   ///< Clear Timer on Compare Match mode
#define TIMER0_FASTPWM_MODE        3   ///< Fast PWM mode

// PWM output modes
#define DISCONNECTED                0   ///< PWM output disconnected
#define NON_INVERTING               2   ///< Non-inverting PWM mode
#define INVERTING                   3   ///< Inverting PWM mode

/**
 * @brief Initializes Timer0 with the configured mode and settings.
 *
 * Configures Timer0 based on the mode and prescaler defined in the configuration file.
 * Sets the initial value for Timer0.
 */
void TIMER0_init(void);

/**
 * @brief Starts Timer0 with the configured settings.
 *
 * Begins Timer0 operation with the previously set mode and prescaler.
 */
void TIMER0_Start(void);

/**
 * @brief Stops Timer0 operation.
 *
 * Disables Timer0, stopping any ongoing counting or PWM generation.
 */
void TIMER0_Stop(void);

/**
 * @brief Sets the preload value for Timer0.
 *
 * @param preload (IN) The value to preload into Timer0's counter register.
 * @return None
 */
void TIMER0_Preload(u8 preload);

/**
 * @brief Enables Timer0 overflow interrupt.
 *
 * Configures Timer0 to generate an interrupt on overflow.
 */
void TIMER0_IntrrupetEnable_OV(void);

/**
 * @brief Disables Timer0 overflow interrupt.
 *
 * Disables Timer0 overflow interrupt generation.
 */
void TIMER0_IntrrupetDisable_OV(void);

/**
 * @brief Enables Timer0 compare match interrupt.
 *
 * Configures Timer0 to generate an interrupt on compare match.
 */
void TIMER0_IntrrupetEnable_OC(void);

/**
 * @brief Disables Timer0 compare match interrupt.
 *
 * Disables Timer0 compare match interrupt generation.
 */
void TIMER0_IntrrupetDisable_OC(void);

/**
 * @brief Sets the value for Timer0 compare match register.
 *
 * @param value (IN) The value to set in the Timer0 Output Compare register.
 * @return None
 */
void TIMER0_OC_Value(u8 value);

/**
 * @brief Configures Timer0 for Fast PWM mode.
 *
 * Sets the PWM mode for Timer0 based on the configuration defined.
 */
void FAST_PWM_MODE(void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
