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


void Serial_Send_String(unsigned char * StringToSend);
unsigned char Serial_Send_Unsigned_Number(unsigned int NumberToSend);

#endif /* SOURCES_SERIAL_DRIVER_H_ */
