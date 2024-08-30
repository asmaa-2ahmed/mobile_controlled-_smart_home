/*
 * TIMER_Private.h
 *
 * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/* Define the Timer0 register addresses and macros */

/* Timer0 Registers */
#define TCNT0       (*(volatile u8*)0x52) // Timer/Counter0 Register - Address 0x52
#define TCCR0       (*(volatile u8*)0x53) // Timer/Counter0 Control Register - Address 0x53
#define TIMSK       (*(volatile u8*)0x59) // Timer/Counter Interrupt Mask Register - Address 0x59
#define TIFR        (*(volatile u8*)0x58) // Timer/Counter Interrupt Flag Register - Address 0x58
#define OCR0        (*(volatile u8*)0x5c) // Timer/Counter0 Output Compare Register - Address 0x5c

/* TCCR0 (Timer/Counter0 Control Register) Bit Positions */
#define CS00     0 // Clock Select Bit 0
#define CS01     1 // Clock Select Bit 1
#define CS02     2 // Clock Select Bit 2
#define WGM01    3 // Waveform Generation Mode Bit 1
#define COM00    4 // Compare Match Output Mode Bit 0
#define COM01    5 // Compare Match Output Mode Bit 1
#define WGM00    6 // Waveform Generation Mode Bit 0
#define FOC0     7 // Force Output Compare

/* TIMSK (Timer/Counter Interrupt Mask Register) Bit Positions */
#define TOIE0    0 // Timer/Counter0 Overflow Interrupt Enable
#define OCIE0    1 // Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE1    2 // Timer/Counter1 Overflow Interrupt Enable (not used in this file)
#define OCIE1B   3 // Timer/Counter1 Output Compare Match B Interrupt Enable (not used in this file)
#define OCIE1A   4 // Timer/Counter1 Output Compare Match A Interrupt Enable (not used in this file)
#define TICIE1   5 // Timer/Counter1 Input Capture Interrupt Enable (not used in this file)
#define TICIE2   6 // Timer/Counter2 Input Capture Interrupt Enable (not used in this file)
#define OCIE2    7 // Timer/Counter2 Output Compare Match Interrupt Enable (not used in this file)

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
