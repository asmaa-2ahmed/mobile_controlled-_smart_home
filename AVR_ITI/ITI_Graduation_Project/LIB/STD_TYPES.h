/*
 * STD_TYPES.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Asmaa & Renad & Arwa
 *
 * This header file defines standard data types that are commonly used across embedded systems
 * projects. These types provide more intuitive names for various sizes of integers and floating
 * point numbers, ensuring consistent usage across different parts of the project.
 */

#ifndef LIB_STD_TYPES_H_   // Include guard to prevent multiple inclusions of the header file
#define LIB_STD_TYPES_H_

// Unsigned data types
typedef unsigned char      u8;   // 8-bit unsigned integer (0 to 255)
typedef unsigned short int u16;  // 16-bit unsigned integer (0 to 65535)
typedef unsigned long int  u32;  // 32-bit unsigned integer (0 to 4294967295)

// Signed data types
typedef signed char        s8;   // 8-bit signed integer (-128 to 127)
typedef signed short int   s16;  // 16-bit signed integer (-32768 to 32767)
typedef signed long int    s32;  // 32-bit signed integer (-2147483648 to 2147483647)

// Floating-point data types
typedef float              f32;  // 32-bit floating point
typedef double             f64;  // 64-bit floating point

// Define NULL pointer as (void*)0
#define NULLPTR ((void*)0)

#endif /* LIB_STD_TYPES_H_ */
