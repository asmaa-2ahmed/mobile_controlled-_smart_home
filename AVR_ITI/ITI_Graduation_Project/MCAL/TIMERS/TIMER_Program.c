/*
 * TIMER_Program.c
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#include "TIMER_Interface.h" // Include Timer interface functions
/**
 * @brief Initializes Timer0 with the specified mode and settings.
 *
 * This function configures Timer0 according to the mode selected in TIMER0_Mode
 * and sets the initial value for the Timer. It also enables the appropriate
 * interrupt based on the mode.
 *
 * @param None
 * @return void
 */
void TIMER0_init(void)
{
    /* MODE SELECT */
    switch(TIMER0_Mode)
    {
        case TIMER0_NORMAL_MODE:
            CLEAR_BIT(TCCR0, WGM00); // Set WGM00 bit to 0 for NORMAL mode
            CLEAR_BIT(TCCR0, WGM01); // Set WGM01 bit to 0 for NORMAL mode
            /* ENABLE OVERFLOW INTERRUPT */
            TIMER0_IntrrupetEnable_OV(); // Enable Timer0 overflow interrupt
            break;
        case TIMER0_PHASECORRECT_MODE:
            SET_BIT(TCCR0, WGM00); // Set WGM00 bit to 1 for PHASECORRECT mode
            CLEAR_BIT(TCCR0, WGM01); // Set WGM01 bit to 0 for PHASECORRECT mode
            break;
        case TIMER0_CTC_MODE:
            CLEAR_BIT(TCCR0, WGM00); // Set WGM00 bit to 0 for CTC mode
            SET_BIT(TCCR0, WGM01); // Set WGM01 bit to 1 for CTC mode
            /* ENABLE COMPARE MATCH INTERRUPT */
            TIMER0_IntrrupetEnable_OC(); // Enable Timer0 compare match interrupt
            break;
        case TIMER0_FASTPWM_MODE:
            SET_BIT(TCCR0, WGM00); // Set WGM00 bit to 1 for FASTPWM mode
            SET_BIT(TCCR0, WGM01); // Set WGM01 bit to 1 for FASTPWM mode
            break;
        default:
            break; // Do nothing if mode is not recognized
    }

    /* SET INITIAL VALUE */
    TIMER0_Preload(TIMER0_INITIAL_VALUE); // Load the initial value into Timer0
}

/**
 * @brief Starts Timer0 with the specified prescaler.
 *
 * This function configures Timer0 with the selected prescaler value
 * to control the timer's frequency and operation.
 *
 * @param None
 * @return void
 */
void TIMER0_Start(void)
{
    /* SELECT PRESCALER */
    switch(TIMER0_Prescaler)
    {
        case TIMER0_SCALER_1:
            SET_BIT(TCCR0, CS00); // Set CS00 bit to 1 for prescaler 1
            break;
        case TIMER0_SCALER_1024:
            SET_BIT(TCCR0, CS00); // Set CS00 bit to 1
            SET_BIT(TCCR0, CS02); // Set CS02 bit to 1 for prescaler 1024
            break;
        case TIMER0_SCALER_256:
            SET_BIT(TCCR0, CS02); // Set CS02 bit to 1 for prescaler 256
            break;
        case TIMER0_SCALER_64:
            SET_BIT(TCCR0, CS00); // Set CS00 bit to 1
            SET_BIT(TCCR0, CS01); // Set CS01 bit to 1 for prescaler 64
            break;
        case TIMER0_SCALER_8:
            SET_BIT(TCCR0, CS01); // Set CS01 bit to 1 for prescaler 8
            break;
        case EXTERNAL_RISING:
            SET_BIT(TCCR0, CS01); // Set CS01 bit to 1
            SET_BIT(TCCR0, CS02); // Set CS02 bit to 1 for external clock on rising edge
            break;
        case EXTERNAL_FALLING:
            SET_BIT(TCCR0, CS00); // Set CS00 bit to 1
            SET_BIT(TCCR0, CS01); // Set CS01 bit to 1
            SET_BIT(TCCR0, CS02); // Set CS02 bit to 1 for external clock on falling edge
            break;
        default:
            break; // Do nothing if prescaler is not recognized
    }
}

/**
 * @brief Configures Timer0 for FAST PWM mode.
 *
 * This function sets the compare output mode for FAST PWM operation based on the
 * PWM_MODE configuration.
 *
 * @param None
 * @return void
 */
void FAST_PWM_MODE(void)
{
    switch(PWM_MODE)
    {
        case DISCONNECTED:
            CLEAR_BIT(TCCR0, COM00); // Set COM00 bit to 0 to disconnect PWM
            CLEAR_BIT(TCCR0, COM01); // Set COM01 bit to 0 to disconnect PWM
            break;
        case NON_INVERTING:
            CLEAR_BIT(TCCR0, COM00); // Set COM00 bit to 0 for non-inverting mode
            SET_BIT(TCCR0, COM01);   // Set COM01 bit to 1 for non-inverting mode
            break;
        case INVERTING:
            SET_BIT(TCCR0, COM00);   // Set COM00 bit to 1 for inverting mode
            SET_BIT(TCCR0, COM01);   // Set COM01 bit to 1 for inverting mode
            break;
        default:
            break; // Do nothing if PWM mode is not recognized
    }
}

/**
 * @brief Enables Timer0 overflow interrupt.
 *
 * This function sets the TOIE0 bit in the TIMSK register to enable the Timer0
 * overflow interrupt.
 *
 * @param None
 * @return void
 */
void TIMER0_IntrrupetEnable_OV(void)
{
    SET_BIT(TIMSK, TOIE0); // Enable Timer0 overflow interrupt
}

/**
 * @brief Disables Timer0 overflow interrupt.
 *
 * This function clears the TOIE0 bit in the TIMSK register to disable the Timer0
 * overflow interrupt.
 *
 * @param None
 * @return void
 */
void TIMER0_IntrrupetDisable_OV(void)
{
    CLEAR_BIT(TIMSK, TOIE0); // Disable Timer0 overflow interrupt
}

/**
 * @brief Enables Timer0 compare match interrupt.
 *
 * This function sets the OCIE0 bit in the TIMSK register to enable the Timer0
 * compare match interrupt.
 *
 * @param None
 * @return void
 */
void TIMER0_IntrrupetEnable_OC(void)
{
    SET_BIT(TIMSK, OCIE0); // Enable Timer0 compare match interrupt
}

/**
 * @brief Disables Timer0 compare match interrupt.
 *
 * This function clears the OCIE0 bit in the TIMSK register to disable the Timer0
 * compare match interrupt.
 *
 * @param None
 * @return void
 */
void TIMER0_IntrrupetDisable_OC(void)
{
    CLEAR_BIT(TIMSK, OCIE0); // Disable Timer0 compare match interrupt
}

/**
 * @brief Stops Timer0 operation.
 *
 * This function stops Timer0 by clearing the TCCR0 register.
 *
 * @param None
 * @return void
 */
void TIMER0_Stop(void)
{
    TCCR0 = 0x00; // Clear TCCR0 register to stop Timer0
}

/**
 * @brief Sets the preload value for Timer0.
 *
 * This function sets the TCNT0 register with the specified preload value.
 *
 * @param preload (IN) - Value to preload into Timer0 (0-255)
 * @return void
 */
void TIMER0_Preload(u8 preload)
{
    TCNT0 = preload; // Load the preload value into TCNT0 register
}

/**
 * @brief Sets the output compare value for Timer0.
 *
 * This function sets the OCR0 register with the specified compare value.
 *
 * @param value (IN) - Value to set in OCR0 register (0-255)
 * @return void
 */
void TIMER0_OC_Value(u8 value)
{
    OCR0 = value; // Load the compare value into OCR0 register
}
