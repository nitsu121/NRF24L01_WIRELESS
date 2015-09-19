/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

#define NUMBER_OF_INTERRUPT_FLAGS 7

unsigned char Flag[NUMBER_OF_INTERRUPT_FLAGS] = {0, 0, 0, 0, 0, 0};

void Delay_ms(unsigned int milliSecs)
{
	unsigned int milliSecCount = 0;
	//GetSetInterruptFlag(unsigned char FlagNumber, unsigned char SetNotGet, unsigned char ValueToSet);
	GetSetInterruptFlag(6, 1, 0);

	while((milliSecs + 1) > milliSecCount)
	{
		while(11 > GetSetInterruptFlag(6, 0, 0))
		{

		}
		GetSetInterruptFlag(6, 1, 0);
		milliSecCount++;
	}
}



unsigned char GetSetInterruptFlag(unsigned char FlagNumber, unsigned char SetNotGet, unsigned char ValueToSet)
{
	unsigned char ReturnFlagValue = 0;

	if((NUMBER_OF_INTERRUPT_FLAGS - 1) < FlagNumber)
	{
		ReturnFlagValue = 255;
	}
	else
	{
		if(SetNotGet)
		{
			Flag[FlagNumber] = ValueToSet;
		}
		else
		{
			ReturnFlagValue = Flag[FlagNumber];
		}
	}
	return (ReturnFlagValue);
}


void PORTA_IRQHandler(void)
{
  /* Clear interrupt flag.*/
	Flag[0] = 1;
  PORT_HAL_ClearPortIntFlag(PORTA_BASE_PTR);
  /* Write your code here ... */
}

void PORTB_IRQHandler(void)
{
	Flag[1] = 1;
  PORT_HAL_ClearPortIntFlag(PORTB_BASE_PTR);
  /* Write your code here ... */
}

#define RED_RGB_ON GPIO_DRV_ClearPinOutput(RED_RGB)
#define RED_RGB_OFF GPIO_DRV_SetPinOutput(RED_RGB)

#define BLUE_RGB_ON GPIO_DRV_ClearPinOutput(BLUE_RGB)
#define BLUE_RGB_OFF GPIO_DRV_SetPinOutput(BLUE_RGB)

#define GREEN_RGB_ON GPIO_DRV_ClearPinOutput(GREEN_RGB)
#define GREEN_RGB_OFF GPIO_DRV_SetPinOutput(GREEN_RGB)

#define GET_SW2 GPIO_DRV_ReadPinInput(SW2)
#define GET_SW3 GPIO_DRV_ReadPinInput(SW3)

void PORTC_IRQHandler(void)
{
	Flag[2] = 1;

  PORT_HAL_ClearPortIntFlag(PORTC_BASE_PTR);
  /* Write your code here ... */
}

void PORTD_IRQHandler(void)
{
	Flag[3] = 1;
  PORT_HAL_ClearPortIntFlag(PORTD_BASE_PTR);
  /* Write your code here ... */
}

void PORTE_IRQHandler(void)
{
	Flag[4] = 1;
  PORT_HAL_ClearPortIntFlag(PORTE_BASE_PTR);
  /* Write your code here ... */
}

void PIT0_IRQHandler(void)
{
  Flag[5]++;
  /* Clear interrupt flag.*/
  PIT_HAL_ClearIntFlag(g_pitBase[FSL_PITTIMER1], FSL_PITTIMER1_CHANNEL);
  /* Write your code here ... */
}

void FTM0_IRQHandler(void)
{
  FTM_DRV_IRQHandler(FSL_FLEXTIMER1);
  /* Write your code here ... */
}

/*! dspiCom1 IRQ handler */
void SPI1_IRQHandler(void)
{
#if DSPICOM1_DMA_MODE
  DSPI_DRV_EdmaIRQHandler(FSL_DSPICOM1);
#else
  DSPI_DRV_IRQHandler(FSL_DSPICOM1);
#endif
  /* Write your code here ... */
}

void PIT1_IRQHandler(void)
{
  Flag[6]++;
  /* Clear interrupt flag.*/
  PIT_HAL_ClearIntFlag(g_pitBase[FSL_PIT100US], FSL_PIT100US_CHANNEL);
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
