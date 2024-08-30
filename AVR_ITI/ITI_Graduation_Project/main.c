/*
 * main.c
 *
 * Created on: Aug 19, 2024
 * Author: Arwa Mekawy
 */

#include "APP/SmartHome_Interface.h" // Ensure this path is correct
#include "MCAL/UART/UART_Interface.h" // Ensure this path is correct
#include "MCAL/DIO/DIO_Interface.h" // Ensure this path is correct
#include <util/delay.h> // Include delay functions from AVR library
#include <stdint.h> // Include for uint8_t type

int main(void)
{
    // Initialize the smart home system
    SMART_INIT();

    // Variable to store received command
    uint8_t command = 0; // Use uint8_t for standard integer type

    // Main loop
    while (1)
    {
        // Prompt user for input
        UART_TransmitString("Select an option:\n");
        UART_TransmitString("A. LED\n");
        UART_TransmitString("B. Buzzer\n");
        UART_TransmitString("C. Solenoid Door\n");

        // Wait for user input
        command = UART_ReceiveByte();

        switch (command)
        {
            case 'A':
                UART_TransmitString("LED Control:\n");
                UART_TransmitString("1. ON\n");
                UART_TransmitString("2. OFF\n");

                // Wait for user input
                command = UART_ReceiveByte();
                if (command == '1')
                {
                    LED_CONTROL('1'); // Turn LED ON
                    UART_TransmitString("LED is ON\n");
                }
                else if (command == '2')
                {
                    LED_CONTROL('2'); // Turn LED OFF
                    UART_TransmitString("LED is OFF\n");
                }
                else
                {
                    UART_TransmitString("Invalid LED command\n");
                }
                break;

            case 'B':
                UART_TransmitString("Buzzer Control:\n");
                UART_TransmitString("1. ON\n");
                UART_TransmitString("2. OFF\n");

                // Wait for user input
                command = UART_ReceiveByte();
                if (command == '1')
                {
                    vSet_Pin_OUTPUTvalue(PORT_C, BUZZER_PIN, HIGH); // Turn Buzzer ON
                    UART_TransmitString("Buzzer is ON\n");
                }
                else if (command == '2')
                {
                    vSet_Pin_OUTPUTvalue(PORT_C, BUZZER_PIN, LOW); // Turn Buzzer OFF
                    UART_TransmitString("Buzzer is OFF\n");
                }
                else
                {
                    UART_TransmitString("Invalid Buzzer command\n");
                }
                break;

            case 'C':
                UART_TransmitString("Solenoid Door Control:\n");
                UART_TransmitString("1. OPEN\n");
                UART_TransmitString("2. CLOSE\n");

                // Wait for user input
                command = UART_ReceiveByte();
                if (command == '1')
                {
                    DOOR_CONTROL(OPEN); // Open the door
                    UART_TransmitString("Door is OPEN\n");
                }
                else if (command == '2')
                {
                    DOOR_CONTROL(CLOSE); // Close the door
                    UART_TransmitString("Door is CLOSED\n");
                }
                else
                {
                    UART_TransmitString("Invalid Door command\n");
                }
                break;

            default:
                UART_TransmitString("Invalid option\n");
                break;
        }

        // Short delay to prevent command overlap
        _delay_ms(100);
    }

    return 0;
}
