/* ###################################################################
**     Filename    : main.c
**     Project     : TestKSDKProjectSerial
**     Processor   : MK64FN1M0VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-08-27, 12:41, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "gpio1.h"
#include "pitTimer1.h"
#include "flexTimer1.h"
#include "SERIAL1.h"
#include "dspiCom1.h"
#include "pit100us.h"
#include "NRF24L01_DRIVER.h"
#include "Serial_Driver.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */

#define RED_RGB_ON GPIO_DRV_ClearPinOutput(RED_RGB)
#define RED_RGB_OFF GPIO_DRV_SetPinOutput(RED_RGB)

#define BLUE_RGB_ON GPIO_DRV_ClearPinOutput(BLUE_RGB)
#define BLUE_RGB_OFF GPIO_DRV_SetPinOutput(BLUE_RGB)

#define GREEN_RGB_ON GPIO_DRV_ClearPinOutput(GREEN_RGB)
#define GREEN_RGB_OFF GPIO_DRV_SetPinOutput(GREEN_RGB)

#define GET_SW2 GPIO_DRV_ReadPinInput(SW2)
#define GET_SW3 GPIO_DRV_ReadPinInput(SW3)

#define GET_IRQ GPIO_DRV_ReadPinInput(PTC18)
	//if((1 << 18) & GPIO_DRV_ReadPinInput(SW2))
	//BLUE_RGB_ON;

#if 0
/*!
* \brief Writes a byte and reads the value
* \param val Value to write. This value will be shifted out
* \return The value shifted in
*/
static uint8_t SPI_WriteRead(uint8_t val) {
  uint8_t ch;

  while (SM1_GetCharsInTxBuf()!=0) {} /* wait until tx is empty */
  while (SM1_SendChar(val)!=ERR_OK) {} /* send character */
  while (SM1_GetCharsInTxBuf()!=0) {} /* wait until data has been sent */
  while (SM1_GetCharsInRxBuf()==0) {} /* wait until we receive data */
  while (SM1_RecvChar(&ch)!=ERR_OK) {} /* get data */
  return ch;
}
#endif

char SendArray[10];
char ReadArray[10];

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  uint8_t String_Test[] = "Hello!! \n";
  UART_DRV_SendData(FSL_SERIAL1, String_Test, sizeof(String_Test));
  uint8_t Temp[2] = {sizeof(unsigned int), 0};
  //UART_DRV_SendData(FSL_SERIAL1, Temp, 2);

  RED_RGB_ON;
  Delay_ms(1000);
  RED_RGB_OFF;

  Init_NRF24L_Reciever();
  //Init_NRF24L_Transmitter();

  RED_RGB_ON;
  Delay_ms(1000);
  RED_RGB_OFF;

  unsigned char NRF_Recieve_Array[100];
  unsigned char ArrayIn[50];
  unsigned char ArrayOut[50];
  unsigned char PayloadOut[5]; // = //{'J', 'U', 'S', 'T', 'I'};

  CE_ON;
  while(1)
  {
	  if(0 == GET_IRQ)
	  {
		  BLUE_RGB_ON;
		  ReadPayload(NRF_Recieve_Array, 5);
		  Serial_Send_String("We Recieved Some Bytes\n");
		  Delay_ms(10);
		  Serial_Send_String("We Got: ");
		  Delay_ms(10);
		  UART_DRV_SendData(FSL_SERIAL1, NRF_Recieve_Array, 5);
		  Clear_NRF_Int_Flags();
		  while(0 == GET_IRQ)
		  {
		  }
	  }
	  else
	  {
		  BLUE_RGB_OFF;
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
