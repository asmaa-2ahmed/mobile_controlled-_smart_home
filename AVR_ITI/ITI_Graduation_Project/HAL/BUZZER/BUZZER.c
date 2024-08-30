/*
 * BUZZER.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 */

#include "BUZZER.h"                     // Include BUZZER header

/**
 * @brief Initialize the buzzer pin
 *
 * This function sets the buzzer pin as an output to control the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vInit(void) {
    vSet_Pin_Direction(BUZZER_PORT, BUZZER_PIN, OUTPUT);  // Set buzzer pin as output
}

/**
 * @brief Turn the buzzer on
 *
 * This function sets the buzzer pin to high, activating the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vTurnOn(void) {
    vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, HIGH);  // Set buzzer pin to high
}

/**
 * @brief Turn the buzzer off
 *
 * This function sets the buzzer pin to low, deactivating the buzzer.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vTurnOff(void) {
    vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, LOW);   // Set buzzer pin to low
}

/**
 * @brief Activate the siren alarm
 *
 * This function generates a siren-like sound by toggling the buzzer on and off
 * in a rapid pattern. The buzzer blinks 10 times with a delay between each state change.
 *
 * (IN)  No input parameters.
 * (OUT) No output parameters.
 *
 * @return void
 */
void BUZZER_vSirenAlarm(void) {
    for (int i = 0; i < 10; i++) { // Blink buzzer 10 times
        vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, HIGH);  // Turn on buzzer
        _delay_ms(500);  // Delay for 500 milliseconds (requires <util/delay.h> or similar delay function)
        vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, LOW);   // Turn off buzzer
        _delay_ms(500);  // Delay for 500 milliseconds
    }
}
