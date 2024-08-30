/*
 * Solenoid_Program.c
 *
 * Created on: Aug 18, 2024
 * Author: Asmaa & Renad & Arwa
 */

#include "Solenoid_Interface.h"


/**
 * @brief Initializes the solenoid control system.
 *
 * This function sets up the pin connected to the solenoid as OUTPUT.
 *
 * @param None
 * @return void
 */
void Solenoid_Init(void)
{
    vSet_Pin_Direction(SOLO_PORT, SOLO_PIN, OUTPUT); // Set solenoid pin as OUTPUT
}

/**
 * @brief Activates the solenoid.
 *
 * This function turns the solenoid ON by setting the corresponding pin HIGH.
 *
 * @param None
 * @return void
 */
void Solenoid_Activate(void)
{
    vSet_Pin_OUTPUTvalue(SOLO_PORT, SOLO_PIN, HIGH); // Set solenoid pin HIGH
}

/**
 * @brief Deactivates the solenoid.
 *
 * This function turns the solenoid OFF by setting the corresponding pin LOW.
 *
 * @param None
 * @return void
 */
void Solenoid_Deactivate(void)
{
    vSet_Pin_OUTPUTvalue(SOLO_PORT, SOLO_PIN, LOW); // Set solenoid pin LOW
}
