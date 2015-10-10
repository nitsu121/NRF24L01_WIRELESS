/*
 * Serial_Driver.c
 *
 *  Created on: Sep 1, 2015
 *      Author: Justin.Flor
 */


#include "Serial_Driver.h"

void Serial_Send_String(unsigned char * StringToSend)
{
	unsigned char NumberToSend = 0;
	unsigned char TempCounter = 0;

	while(!(0 == StringToSend[TempCounter]))
	{
		TempCounter++;
	}

	//UART_DRV_SendData(FSL_SERIAL1, "BOgA Fota Boga. \n", sizeof("BOgA Fota Boga. \n"));
	UART_DRV_SendData(FSL_SERIAL1, StringToSend, TempCounter);
}

unsigned char Serial_Send_Unsigned_Number(unsigned int NumberToSend)
{
	unsigned char ReturnFlag = 0;
	unsigned int TempNumber = NumberToSend;
	unsigned char OutputNumber[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned char DigitCount = 0;
	unsigned char LoopCounter = 0;
	unsigned char Flag = 0;
	unsigned char DigitOut[2] = {0, 0};

	if(0 == NumberToSend)
	{
		DigitOut[0] = 48;
		Serial_Send_String(DigitOut);
	}
	else
	{
		while(10 > LoopCounter)
		{
			OutputNumber[LoopCounter] = TempNumber % 10;
			TempNumber /= 10;
			LoopCounter++;
		}

		LoopCounter = 9;

		while((0 < LoopCounter) && (0 == Flag))
		{
			if(0 == OutputNumber[LoopCounter])
			{
				LoopCounter--;
			}
			else
			{
				Flag = 1;
			}
		}

		while(0 < LoopCounter)
		{
			DigitOut[0] = OutputNumber[LoopCounter] + 48;
			Serial_Send_String(DigitOut);
			LoopCounter--;
		}

		DigitOut[0] = OutputNumber[LoopCounter] + 48;
		Serial_Send_String(DigitOut);
	}
	return (ReturnFlag);
}

unsigned char Recieve_Bytes_In(unsigned char * ReadArray, unsigned char MaxArraySize)
{
	unsigned char NumOfBytesRx = 0;
	unsigned char FailSafeReadArray;

	  if(1 == UART_HAL_IsRxFifoEmpty(UART1_BASE_PTR)) // this means its empty.
	  {
	  }
	  else  // got something
	  {
		  while(0 == UART_HAL_IsRxFifoEmpty(UART1_BASE_PTR)) // keep going one byte at a time till we gots it all.
		  {
			  if(MaxArraySize > NumOfBytesRx)
			  {
				  UART_DRV_ReceiveDataBlocking(FSL_SERIAL1, &ReadArray[NumOfBytesRx], 1, 100);
				  NumOfBytesRx++;
			  }
			  else
			  {
				  UART_DRV_ReceiveDataBlocking(FSL_SERIAL1, &FailSafeReadArray, 1, 50);
				  NumOfBytesRx = 0;
			  }

			  UART_DRV_SendData(FSL_SERIAL1, &ReadArray[NumOfBytesRx], 1);
			  Delay_ms(10);
		  }
	  }

	return (NumOfBytesRx);
}

unsigned char Recieve_Command_In(struct SERIAL_COMMAND * RecieveCommand)
{
	unsigned char GotValidCommand = 0;



	return (GotValidCommand);
}

