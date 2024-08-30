/*
 * SmartHome_Program.c
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#include "SmartHome_Interface.h" // Include Smart Home interface definitions


// Predefined usernames and passwords for authentication
const char usernames[MAX_USERS][6] =
{
    "user1", "user2", "user3", "user4", "user5",
    "user6", "user7", "user8", "user9", "user0"
};

const char pass[MAX_USERS][6] =
{
    "pass1", "pass2", "pass3", "pass4", "pass5",
    "pass6", "pass7", "pass8", "pass9", "pass0"
};

/**
 * @brief Initializes the smart home system.
 *
 * This function sets up UART communication and configures the pins
 * for LED, Buzzer, and Door control. It also sets the direction of the pins
 * to INPUT or OUTPUT as required.
 *
 * @param None
 * @return void
 */
void SMART_INIT(void)
{
    UART_Init(); // Initialize UART for communication

    // Configure pin directions for hardware components
    vSet_Pin_Direction(PORT_D, PIN_0, INPUT); // Set PORT_D, PIN_0 as INPUT for UART RX
    vSet_Pin_Direction(PORT_D, PIN_1, OUTPUT); // Set PORT_D, PIN_1 as OUTPUT for UART TX

    // Configure LED pin
    vSet_Pin_Direction(PORT_A, LED_PIN, OUTPUT); // Set PORT_A, LED_PIN as OUTPUT

    // Configure Buzzer pin
    vSet_Pin_Direction(PORT_C, BUZZER_PIN, OUTPUT); // Set PORT_C, BUZZER_PIN as OUTPUT

    // Configure Door pin (Solenoid lock)
    vSet_Pin_Direction(PORT_D, DOOR_PIN, OUTPUT); // Set PORT_D, DOOR_PIN as OUTPUT
}

/**
 * @brief Handles user authentication.
 *
 * This function prompts the user to enter a username and password,
 * and verifies them against predefined usernames and passwords. It allows
 * a specified number of authentication attempts.
 *
 * @param None
 * @return int (OUT) - Status code representing the result of the authentication:
 *                      0: Authentication failed
 *                      1: Authentication succeeded
 */
int AUTHENICATION(void)
{
    char rUSERNAME[20]; // Buffer to store received username
    char rPASSWORD[20]; // Buffer to store received password
    char i = 0;
    char authSuccess = 0; // Flag to check if authentication is successful

    // Allow up to MAX_TRIALS attempts for authentication
    for (i = 0; i < MAX_TRIALS; i++)
    {
        UART_TransmitString("ENTER USERNAME:"); // Prompt user for username
        UART_ReceiveString((char*)rUSERNAME, MAX_LENGTH); // Receive username

        UART_TransmitString("ENTER PASSWORD:"); // Prompt user for password
        UART_ReceiveString((char*)rPASSWORD, MAX_LENGTH); // Receive password

        // Check if received username and password match any stored credentials
        for (u8 j = 0; j < MAX_USERS; j++)
        {
            if ((strcmp((char*)rUSERNAME, usernames[j]) == 0) &&
                (strcmp((char*)rPASSWORD, pass[j]) == 0))
            {
                UART_TransmitString("AUTHENTICATION SUCCEEDED\n"); // Notify success
                UART_TransmitString("     ");
                authSuccess = 1; // Set flag to indicate success
                return 1; // Return success
            }
        }

        UART_TransmitString("AUTHENTICATION FAILED\n"); // Notify failure
        UART_TransmitString("     ");

        if (authSuccess) // Break if authentication succeeded
        {
            break;
        }
    }

    // If authentication fails after MAX_TRIALS attempts, activate the buzzer
    if (i >= MAX_TRIALS && !authSuccess)
    {
        vSet_Pin_OUTPUTvalue(PORT_C, BUZZER_PIN, HIGH); // Activate buzzer
        _delay_ms(1000); // Wait for 1 second
        vSet_Pin_OUTPUTvalue(PORT_C, BUZZER_PIN, LOW); // Deactivate buzzer
    }

    return 0; // Return failure
}

/**
 * @brief Controls the LED based on the provided order.
 *
 * This function turns the LED on or off based on the order received.
 *
 * @param order (IN) - Command to control the LED:
 *                     '1': Turn LED ON
 *                     '2': Turn LED OFF
 * @return void
 */
void LED_CONTROL(u8 order)
{
    if (order == '1') // If order is '1', turn LED ON
    {
        vSet_Pin_OUTPUTvalue(PORT_A, LED_PIN, HIGH); // Set LED pin HIGH
        UART_TransmitString("LED IS ON"); // Notify LED status
    }
    else if (order == '2') // If order is '2', turn LED OFF
    {
        vSet_Pin_OUTPUTvalue(PORT_A, LED_PIN, LOW); // Set LED pin LOW
        UART_TransmitString("LED IS OFF"); // Notify LED status
    }
}

/**
 * @brief Controls the door lock based on the provided order.
 *
 * This function locks or unlocks the door based on the order received.
 *
 * @param order (IN) - Command to control the door:
 *                     '1': Lock the door
 *                     '2': Unlock the door
 * @return void
 */
void DOOR_CONTROL(u8 order)
{
    if (order == '1') // If order is '1', lock the door
    {
        vSet_Pin_OUTPUTvalue(PORT_D, DOOR_PIN, HIGH); // Set door pin HIGH
        UART_TransmitString("LOCKED"); // Notify door status
    }
    else if (order == '2') // If order is '2', unlock the door
    {
        vSet_Pin_OUTPUTvalue(PORT_D, DOOR_PIN, LOW); // Set door pin LOW
        UART_TransmitString("UNLOCKED"); // Notify door status
    }
}

// The following code has been commented out as it may not be fully functional or intended for a specific use-case
//void servo_angle(u8 angle) // Function to set the angle of the servo motor
//{
//    u16 val = (((u32)1000*angle)/180)+1000; // Calculate pulse width for servo angle (1000 to 2000 microseconds)
//    vTIMER1_Compare_OCR1A(val); // Set the compare match value for Timer1
//}

//void DOOR_STATE(u8 state) // Function to control door state (open or close) using servo
//{
//    vTIMER1_INIT(); // Initialize Timer1
//    vTIMER1_ICR1(20000); // Set Timer1 ICR1 value for servo
//    Timer1_OCRA1Mode(ORA1_NON_INVERTING); // Set Timer1 mode
//    vTIMER1_START(); // Start Timer1

//    while(1) // Infinite loop to handle door state
//    {
//        switch(state)
//        {
//            case CLOSE:
//                servo_angle(0); // Set servo to 0 degrees (close)
//                _delay_ms(1000); // Wait for 1 second
//                break;

//            case OPEN:
//                servo_angle(90); // Set servo to 90 degrees (open)
//                _delay_ms(1000); // Wait for 1 second
//                break;

//            default:
//                servo_angle(0); // Default to close position
//                break;
//        }
//    }
//}
