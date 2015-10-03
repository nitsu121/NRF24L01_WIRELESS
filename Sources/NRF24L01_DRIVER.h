/*
 * NRF24L01_DRIVER.h
 *
 *  Created on: Sep 1, 2015
 *      Author: Justin.Flor
 */

#ifndef SOURCES_NRF24L01_DRIVER_H_
#define SOURCES_NRF24L01_DRIVER_H_


//NRF COMMANDS
#define R_REGISTER 0
#define W_REGISTER 0b00100000

#define R_RX_PAYLOAD 0b01100001
#define W_TX_PAYLOAD 0b10100000
#define FLUSH_TX 0b11100001
#define FLUSH_RX 0b11100010
#define REUSE_TX_PL 0b11100011
#define NOP 0b11111111
//NRF REGISTERS
#define CONFIG 0
#define EN_AA 1
#define EN_RXADDR 2
#define SETUP_AW 3
#define SETUP_RETR 4
#define RF_CH 5
#define RF_SETUP 6
#define STATUS 7
#define OBSERVE_TX 8
#define CD 9
#define RX_ADDR_P0 0x0A
#define RX_ADDR_P1 0x0B
#define RX_ADDR_P2 0x0C
#define RX_ADDR_P3 0x0D
#define RX_ADDR_P4 0x0E
#define RX_ADDR_P5 0x0F
#define TX_ADDR 0x10
#define RX_PW_P0 0x11
#define RX_PW_P1 0x12
#define RX_PW_P2 0x13
#define RX_PW_P3 0x14
#define RX_PW_P4 0x15
#define RX_PW_P5 0x16
#define FIFO_STATUS 0x17


#define CLEAR_TX_INT 0b00100000

#define CE_OFF GPIO_DRV_ClearPinOutput(RF_CE)
#define CE_ON GPIO_DRV_SetPinOutput(RF_CE)

void Init_NRF24L_Transmitter(void);
void Init_NRF24L_Reciever(void);
unsigned char Read_Register(unsigned char RegisterNumber, unsigned char * RecieveArray, unsigned char NumOfBytesToRead);
unsigned char Write_Register(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char * RecievedArray, unsigned char NumOfBytesToRead);
unsigned char Write_Reg_Varified(unsigned char RegisterNumber, unsigned char * SendArray, unsigned char NumOfBytesToRead);
unsigned char Send_Last_Payload(unsigned char NumberOfTimesToSend);
unsigned char Read_Status(void);
unsigned char Flush_Tx(void);
unsigned char Flush_Rx(void);
unsigned char SendNewPayload(unsigned char * PayloadArrayToSend, unsigned char NumberOfBytesToSend);
unsigned char ReadPayload(unsigned char * ReadArray, unsigned char NumberOfBytesToRead);
unsigned char WatchForPayload(unsigned char * ReadArray, unsigned char NumberOfBytesToRead);
void Clear_NRF_Int_Flags(void);

#endif /* SOURCES_NRF24L01_DRIVER_H_ */
