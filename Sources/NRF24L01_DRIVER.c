/*
 * NRF24.01_DRIVER.c
 *
 *  Created on: Sep 1, 2015
 *      Author: Justin.Flor
 */

#include "Events.h"
#include "pin_mux.h"
#include "gpio1.h"
#include "SERIAL1.h"
#include "dspiCom1.h"

#include "NRF24L01_DRIVER.h"


void Clear_NRF_Int_Flags(void)
{
	unsigned char SendArray[2] = {0, 0};
	unsigned char ReadArray[2];
	unsigned char TempStatus = 0;
	TempStatus = Read_Status();
	SendArray[0] = TempStatus & 0xF0;
	Write_Register(7, SendArray, ReadArray, 1); //
}

void Init_NRF24L_Reciever(void)
{

	char TempValue = 0;

	  CE_OFF;
	  Delay_ms(100);
	  //Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead)
	  unsigned char SendArray[2] = {0, 0};
	  unsigned char ReadArray[2];
	  SendArray[0] = 0b00111111;
	  while(!(0b00111111 == TempValue))
	  {
		  Write_Register(0, SendArray, ReadArray, 1); // power up rf mod.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0, &TempValue, 1);
		  Delay_ms(100);
	  }


	  TempValue = 10;
	  SendArray[0] = 0x01;
	  while(!(0x01 == TempValue))
	  {
		  Write_Register(1, SendArray, ReadArray, 1); // disable auto ack.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(1, &TempValue, 1);
		  Delay_ms(100);
	  }

	  TempValue = 0;
	  SendArray[0] = 0x01;
	  while(!(0x01 == TempValue))
	  {
		  Write_Register(2, SendArray, ReadArray, 1); // enable data pipe 0.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(2, &TempValue, 1);
		  Delay_ms(100);
	  }

	  TempValue = 0;
	  SendArray[0] = 0x03;
	  while(!(0x03 == TempValue))
	  {
		  Write_Register(3, SendArray, ReadArray, 1); // use 5 bytes address field width.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(3, &TempValue, 1);
		  Delay_ms(100);
	  }


	  TempValue = 0;
	  SendArray[0] = 0xFF;
	  while(!(0xFF == TempValue))
	  {
		  Write_Register(0x04, SendArray, ReadArray, 1); // data payload widths for pipe0 5 bytes.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0x04, &TempValue, 1);
		  Delay_ms(100);
	  }


	  TempValue = 0;
	  SendArray[0] = 83;
	  while(!(0xFF == TempValue))
	  {
		  Write_Register(0x05, SendArray, ReadArray, 1); // data payload widths for pipe0 5 bytes.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0x05, &TempValue, 1);
		  Delay_ms(100);
	  }



	  TempValue = 0;
	  SendArray[0] = 0x05;
	  while(!(0x05 == TempValue))
	  {
		  Write_Register(0x11, SendArray, ReadArray, 1); // data payload widths for pipe0 5 bytes.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0x11, &TempValue, 1);
		  Delay_ms(100);
	  }
}

void Init_NRF24L_Transmitter(void)
{

	char TempValue = 0;

	  CE_OFF;
	  Delay_ms(100);
	  //Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead)
	  unsigned char SendArray[2] = {0, 0};
	  unsigned char ReadArray[2];
	  SendArray[0] = 0x52;
	  while(!(0x52 == TempValue))
	  {
		  Write_Register(0, SendArray, ReadArray, 1); // power up rf mod.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0, &TempValue, 1);
		  Delay_ms(100);
	  }


	  TempValue = 10;
	  SendArray[0] = 0x00;
	  while(!(0x00 == TempValue))
	  {
		  Write_Register(1, SendArray, ReadArray, 1); // disable auto ack.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(1, &TempValue, 1);
		  Delay_ms(100);
	  }

	  TempValue = 0;
	  SendArray[0] = 0x01;
	  while(!(0x01 == TempValue))
	  {
		  Write_Register(2, SendArray, ReadArray, 1); // enable data pipe 0.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(2, &TempValue, 1);
		  Delay_ms(100);
	  }

	  TempValue = 0;
	  SendArray[0] = 0x01;
	  while(!(0x01 == TempValue))
	  {
		  Write_Register(3, SendArray, ReadArray, 1); // use 5 bytes address field width.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(3, &TempValue, 1);
		  Delay_ms(100);
	  }


	  //SendArray[0] = 0x01;
	  //Write_Register(4, SendArray, ReadArray, 1); // leave as default.

	  //SendArray[0] = 0x01;
	  //Write_Register(5, SendArray, ReadArray, 1); // leave as default this changes the address.

	  //SendArray[0] = 0x01;
	  //Write_Register(6, SendArray, ReadArray, 1); // leave as default.

	  //SendArray[0] = 0x01;
	  //Write_Register(7, SendArray, ReadArray, 1); // status register..

	  TempValue = 0;
	  SendArray[0] = 0x05;
	  while(!(0x05 == TempValue))
	  {
		  Write_Register(0x11, SendArray, ReadArray, 1); // data payload widths for pipe0 5 bytes.
		  Delay_ms(100);
		  //Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
		  Read_Register(0x11, &TempValue, 1);
		  Delay_ms(100);
	  }
}

unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;
	TempSendArray[0] = RegisterNumber | R_REGISTER;

	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, &Send[0], Read, 5, 10000);
	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumOfBytesToRead + 1, 10000);
	ReturnFlag = TempReadArray[0];

	while(NumOfBytesToRead > Counter)
	{
		RecieveArray[Counter] = TempReadArray[Counter + 1];
		Counter++;
	}

	return (ReturnFlag);
}

unsigned char Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;
	TempSendArray[0] = RegisterNumber | W_REGISTER;

	while(NumOfBytesToRead > Counter)
	{
		TempSendArray[Counter + 1] = SendArray[Counter];
		Counter++;
	}

	//DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, &Send[0], Read, 5, 10000);
	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumOfBytesToRead + 1, 10000);
	ReturnFlag = TempReadArray[0];

	Counter = 0;

	while(NumOfBytesToRead > Counter)
	{
		RecievedArray[Counter] = TempReadArray[Counter + 1];
		Counter++;
	}

	return (ReturnFlag);
}

unsigned char Send_Last_Payload(unsigned char NumberOfTimesToSend)
{
	unsigned char ReturnFlag = 0;

	return (ReturnFlag);
}

unsigned char Read_Status()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};
	//unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead)
	Read_Register(0x07, ReadArray, 1);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}


unsigned char WatchForPayload(unsigned char * ReadArray, unsigned char NumberOfBytesToRead)
{
	unsigned char ReturnFlag = 0;
	CE_ON;
	//Delay_ms(10);
	//CE_OFF;

	return (ReturnFlag);
}

unsigned char ReadPayload(unsigned char * ReadArray, unsigned char NumberOfBytesToRead)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[100];
	unsigned char TempReadArray[100];
	unsigned char Count = 0;
	TempSendArray[0] = R_RX_PAYLOAD;

	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumberOfBytesToRead + 1, 10000);

	while(NumberOfBytesToRead > Count)
	{

		ReadArray[Count] = TempReadArray[Count + 1];
		Count++;
	}

	Flush_RX();

	return (ReturnFlag);
}

unsigned char SendNewPayload(unsigned char * PayloadArrayToSend, unsigned char NumberOfBytesToSend)
{
	unsigned char ReturnFlag = 0;
	unsigned char TempSendArray[50];
	unsigned char TempReadArray[50];
	unsigned char Counter = 0;

	Flush_Tx();

	TempSendArray[0] = W_TX_PAYLOAD;

	while(NumberOfBytesToSend > Counter)
	{
		TempSendArray[Counter + 1] = PayloadArrayToSend[Counter];
		Counter++;
	}

	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, TempSendArray, TempReadArray, NumberOfBytesToSend + 1, 10000);
	ReturnFlag = TempReadArray[0];

	CE_ON;
	Delay_ms(10);
	CE_OFF;

	return (ReturnFlag);
}

unsigned char Flush_Tx()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};
	unsigned char SendArray[2] = {FLUSH_TX, 0};
	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, SendArray, ReadArray, 1, 10000);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}

unsigned char Flush_RX()
{
	unsigned char ReturnFlag = 0;
	unsigned char ReadArray[2] = {0, 0};
	unsigned char SendArray[2] = {FLUSH_RX, 0};
	DSPI_DRV_MasterTransferBlocking(FSL_DSPICOM1, NULL, SendArray, ReadArray, 1, 10000);
	ReturnFlag = ReadArray[0];
	return (ReturnFlag);
}


