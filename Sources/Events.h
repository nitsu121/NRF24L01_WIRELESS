/* ###################################################################
**     Filename    : Events.h
**     Project     : TestKSDKProjectSerial
**     Processor   : MK64FN1M0VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-08-27, 12:41, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "gpio1.h"
#include "pitTimer1.h"
#include "flexTimer1.h"
#include "SERIAL1.h"
#include "dspiCom1.h"
#include "pit100us.h"

#ifdef __cplusplus
extern "C" {
#endif 

unsigned char GetSetInterruptFlag(unsigned char FlagNumber, unsigned char SetNotGet, unsigned char ValueToSet);
void Delay_ms(unsigned int milliSecs);

void PORTA_IRQHandler(void);

void PORTB_IRQHandler(void);

void PORTC_IRQHandler(void);

void PORTD_IRQHandler(void);

void PORTE_IRQHandler(void);

void PIT0_IRQHandler(void);

void FTM0_IRQHandler(void);

/*! dspiCom1 IRQ handler */
void SPI1_IRQHandler(void);

void PIT1_IRQHandler(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
