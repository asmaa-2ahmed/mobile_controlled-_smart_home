# Mobile Controlled Home System

This project integrates a mobile application, hardware components, and simulation tools to create a smart home control system. The system allows users to control their home environment through a mobile app, featuring two main subsystems: a safety door and light control. The hardware is programmed in C using Eclipse, the mobile app is developed using Flutter, and the system is simulated using Proteus.

## Features
- **Safety Door Control:** Open and close the door using a mobile app.
- **Light Control:** Turn lights on and off using the mobile app.
- **User Authentication:** Supports 10 users with unique usernames and passwords, connected to Firebase for secure authentication.
- **Security Measures:** An alarm is triggered if the wrong username or password is entered three times, and the system disables for 10 seconds before allowing another attempt.

## Hardware Components
- **AVR Microcontroller (ATmega32):** Core controller of the system.
- **Bluetooth Module (HC-05):** Enables communication between the mobile app and hardware.
- **Solenoid:** Mechanism for locking and unlocking the door.
- **Led:** Used for light control.
- **Buzzer:** Provides an audible alert when security is breached.

## C Code Structure (Eclipse)
- **APP:** Handles the integration between hardware and software .
- **HAL (Hardware Abstraction Layer):** Contains modules for:
  - **Bluetooth:** Manages communication between the mobile app and the microcontroller.
  - **Buzzer:** Controls the alarm system.
  - **Led:** Manages the light control subsystem.
  - **Solenoid:** Controls the door lock mechanism.
- **MCAL (Microcontroller Abstraction Layer):** Contains modules for:
  - **DIO (Digital Input/Output):** Manages digital pins for input and output operations.
  - **Timers:** Handles time-based functions within the system.
  - **UART (Universal Asynchronous Receiver/Transmitter):** Manages serial communication.

## Mobile Application (Flutter)
- Developed using Flutter with Firebase for secure user authentication.
- User-friendly interface to control the home’s safety door and lights.

## Simulation (Proteus)
- The entire hardware setup is simulated using Proteus to visualize the system’s functionality before actual deployment.

## Project Structure
- **/Flutter_ITI/smart_home:** Contains the Flutter code for the mobile app.
- **/AVR_ITI\ITI_Graduation_Project:** C code for programming the AVR microcontroller, structured into APP, HAL, and MCAL.
- **/GRAD_PROJECT.pdsprj:** Proteus simulation files.

## Getting Started
1. **Simulation:**
   - Open the Proteus simulation file to visualize the system.
   - Test the interaction between the app and the simulated hardware.
     
2. **Hardware Setup:**
   - Connect the ATmega32 microcontroller with the Bluetooth module, solenoid, Led, and buzzer as per the circuit diagram.
   - Load the C code onto the microcontroller using Eclipse.

3. **Mobile Application:**
   - Install the Flutter app on your mobile device.
   - Pair the device with the Bluetooth module (HC-05).
   - Use the app to control the safety door and lights.

## Captions for Images
- **System Overview:** A high-level view of the mobile-controlled home system.
- **Hardware Setup:** The physical connections of the microcontroller, Bluetooth module, solenoid, led, and buzzer.
- ![2024-08-19 at 11 38 53 AM](https://github.com/user-attachments/assets/ac60714d-0f33-4f0a-8c3e-a708184f5c16)
  
- **Mobile App Interface:** Screenshot of the Flutter app showing the control options for the safety door and lights.
![01](https://github.com/user-attachments/assets/0df16e7f-1ee5-4c2e-9c4a-f0967f730023)
![02](https://github.com/user-attachments/assets/a94e42c0-34e8-4756-bb4e-395492514f05)
![1](https://github.com/user-attachments/assets/ad395038-61d4-44c7-9e7a-8a52bbd3c48e)
![2](https://github.com/user-attachments/assets/49211be7-c85e-45cc-b2ac-145406991ad0)
![3](https://github.com/user-attachments/assets/89f8ea6c-f35c-4485-b130-8e657276365b)

- **Proteus Simulation:** A snapshot of the Proteus simulation running, showing the interaction between the app and hardware components.
![2024-08-19 at 11 37 11 AM](https://github.com/user-attachments/assets/e92df5d3-41f9-4909-adfe-7322f815a8c7)

## Conclusion
This project demonstrates the integration of mobile applications with hardware control systems, providing a secure and user-friendly solution for home automation. The combination of Flutter, Firebase, C programming in Eclipse, and Proteus simulation ensures a reliable and scalable system.
