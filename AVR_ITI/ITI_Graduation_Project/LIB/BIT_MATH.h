/*
 * BIT_MATH.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file defines macros for common bitwise operations. These macros provide an easy way
 * to manipulate individual bits in a variable, which is especially useful in embedded systems
 * programming for tasks like setting, clearing, toggling, and checking specific bits in hardware
 * registers.
 */

#ifndef LIB_BIT_MATH_H_    // Include guard to prevent multiple inclusions of the header file
#define LIB_BIT_MATH_H_

// Macro to set a specific bit (BITNO) in a variable (VAR)
#define SET_BIT(VAR,BITNO) 		(VAR|=(1<<BITNO))

// Macro to clear a specific bit (BITNO) in a variable (VAR)
#define CLEAR_BIT(VAR,BITNO) 	(VAR&=(~(1<<BITNO)))

// Macro to toggle a specific bit (BITNO) in a variable (VAR)
#define TOG_BIT(VAR,BITNO) 		(VAR^=(1<<BITNO))

// Macro to get the value of a specific bit (BITNO) in a variable (VAR)
#define GET_BIT(VAR,BITNO) 		((VAR>>BITNO)&1)

#endif /* LIB_BIT_MATH_H_ */
