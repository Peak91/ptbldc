/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief Header file for pid.c.
 *
 * - File:               pid.h
 * - Compiler:           IAR EWAAVR 4.11A
 * - Supported devices:  All AVR devices can be used.
 * - AppNote:            AVR221 - Discrete PID controller
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support email: avr@atmel.com
 *
 * $Name$
 * $Revision: 456 $
 * $RCSfile$
 * $Date: 2006-02-16 12:46:13 +0100 (to, 16 feb 2006) $
 *****************************************************************************/

#ifndef PID_H
#define PID_H

#include "stdint.h"

#define PID_DEFAULT_P	200
#define PID_DEFAULT_I	5
#define PID_DEFAULT_D	0

#define SCALING_FACTOR  128

/*! \brief PID Status
 *
 * Setpoints and data used by the PID control algorithm
 */
typedef struct{
	//! Last process value, used to find derivative of process value.
	int16_t lastProcessValue;
	//! Summation of errors, used for integrate calculations
	int32_t sumError;
	//! The Proportional tuning constant, multiplied with SCALING_FACTOR
	int16_t P_Factor;
	//! The Integral tuning constant, multiplied with SCALING_FACTOR
	int16_t I_Factor;
	//! The Derivative tuning constant, multiplied with SCALING_FACTOR
	int16_t D_Factor;
	//! Maximum allowed error, avoid overflow
	int16_t maxError;
	//! Maximum allowed sumerror, avoid overflow
	int32_t maxSumError;
	//	
	int16_t referenceValue;
	//
	int16_t measurementValue;
	//
	int16_t inputValue;
} PID_St;

/*! \brief Maximum values
 *
 * Needed to avoid sign/overflow problems
 */
// Maximum value of variables
#define MAX_INT         INT16_MAX
#define MAX_LONG        INT32_MAX
#define MAX_I_TERM      (MAX_LONG / 2)

// Boolean values
#define FALSE           0
#define TRUE            1

void PID_LoadDefaults(PID_St *pid);
void PID_Init(PID_St *pid);
int16_t PID_Controller(PID_St *pid_st);
void PID_Reset_Integrator(PID_St *pid_st);

#endif
