/*
 * TIMER_Config.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

/**
 * @file TIMER_Config.h
 * @brief Configuration settings for Timer0.
 *
 * This header file contains configuration settings for Timer0, including
 * the prescaler, mode, initial value, and PWM mode.
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

// Prescaler value for Timer0.
// Determines the frequency of the timer clock. Options include:
// TIMER0_SCALER_1, TIMER0_SCALER_8, TIMER0_SCALER_64, TIMER0_SCALER_256, TIMER0_SCALER_1024, EXTERNAL_RISING, EXTERNAL_FALLING.
#define TIMER0_Prescaler     TIMER0_SCALER_256

// Timer0 operating mode.
// Defines the mode of operation for Timer0. Options include:
// TIMER0_NORMAL_MODE, TIMER0_PHASECORRECT_MODE, TIMER0_CTC_MODE, TIMER0_FASTPWM_MODE.
#define TIMER0_Mode          TIMER0_FASTPWM_MODE

// Initial value for Timer0.
// The value that Timer0 starts counting from. It should be set according to the application requirements.
#define TIMER0_INITIAL_VALUE 0

// PWM mode configuration for Timer0.
// Defines the mode of Pulse Width Modulation (PWM). Options include:
// DISCONNECTED, NON_INVERTING, INVERTING.
#define PWM_MODE             INVERTING

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
