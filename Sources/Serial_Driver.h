/*
 * Serial_Driver.h
 *
 *  Created on: Sep 1, 2015
 *      Author: Justin.Flor
 */

#ifndef SOURCES_SERIAL_DRIVER_H_
#define SOURCES_SERIAL_DRIVER_H_

#include "Events.h"
#include "SERIAL1.h"

struct SERIAL_COMMAND
{
	unsigned char c_Address;
	unsigned char c_DataBytes[10];
	unsigned char c_CheckSum;
};

void Serial_Send_String(unsigned char * StringToSend);
unsigned char Serial_Send_Unsigned_Number(unsigned int NumberToSend);

unsigned char Recieve_Command_In(struct SERIAL_COMMAND * RecieveCommand);

unsigned char Recieve_Bytes_In(unsigned char * ReadArray, unsigned char MaxArraySize);

#endif /* SOURCES_SERIAL_DRIVER_H_ */
