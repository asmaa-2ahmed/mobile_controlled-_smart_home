/*
 * UART_conf.h
 *
  * Created on: Aug 16, 2024
 * Author: Asmaa & Renad & Arwa
 */

#ifndef MCAL_UART_UART_CONF_H_
#define MCAL_UART_UART_CONF_H_

#include "../../LIB/BIT_MATH.h"       // Include bitwise operations
#include "../../LIB/STD_TYPES.h"      // Include standard types

/* Select baud rate */
#define BOUD_RATE           BAUD_9600_F_8

/* Select speed mode */
#define SPEED_MODE          NORMAL_SPEED

/* Select Operation mode */
#define OPERATION_MODE      UART_ASYNCH

/* Configure Frame */
/* 1- Select Parity */
#define PARITY              NO_PARITY

/* 2- Select Data Bits */
#define DATA_BITS           DATA_BITS_8

/* 3- Select Number of Stop Bits */
#define STOP_BITS           ONE_STOP_BIT



/*
 * Commented out sections below define alternative configurations
 * that can be used if necessary. These are not active by default.
 */

////////////////////////////////////////
//#define SET_2DS        0
//#define NOT_SET_2DS    1
//#define SPEED_MODE     NOT_SET_2DS
////////////////////////////////////////
//
//#define DISSABLE_PARITY  0
//#define EVEN_PARITY      1
//#define ODD_PARITY       2
//#define PARITY_MODE      DISSABLE_PARITY
////////////////////////////////////////
//#define ONE_STOP        0
//#define TWO_STOP        1
//#define SELECT_STOP     ONE_STOP
////////////////////////////////////////
//#define BIT_5           0
//#define BIT_6           1
//#define BIT_7           2
//#define BIT_8           3
//#define BIT_9           4
//#define SELECT_NUM_BIT  BIT_8
///////////////////////////////////////////

#endif /* MCAL_UART_UART_CONF_H_ */
