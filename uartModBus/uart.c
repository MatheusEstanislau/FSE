#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "crc.h"

#define UART_ADDRESS 0X01
#define RECEIVE_CODE 0X23;
#define RECEIVE_LM35_CODE 0XC1;
#define RECEIVE_POTENTIOMETER_CODE 0XC2;

unsigned char tx_buffer[20];
unsigned char rx_buffer[100];
unsigned char *p_tx_buffer;

int uart0_filestream;
int packageSize = 0;

typedef union
{
  short crc;
  uint8_t bytes[2];
} crcCalculateBytes;

void clearData()
{
  p_tx_buffer = &tx_buffer[0];
}

void initializeUart()
{
  uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY); //Open in non blocking read/write mode
  struct termios options;
  tcgetattr(uart0_filestream, &options);
  options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
  options.c_iflag = IGNPAR;
  options.c_oflag = 0;
  options.c_lflag = 0;
  tcflush(uart0_filestream, TCIFLUSH);
  tcsetattr(uart0_filestream, TCSANOW, &options);

  p_tx_buffer = &tx_buffer[0];
}

void uartWriting(int packageLenght)
{
  int writeFlag = write(uart0_filestream, &tx_buffer[0], packageLenght);
}

void uartReading()
{
  usleep(200000);
  int rx_length = read(uart0_filestream, (void *)rx_buffer, 255);
}

void calculateCRC(int packageLenght)
{
  crcCalculateBytes crc;
  crc.crc = calcula_CRC(tx_buffer, packageLenght);
  memcpy(&tx_buffer[packageLenght], crc.bytes, 2);
  packageSize += 2;
}

void readingPotentiometer()
{
  *p_tx_buffer++ = UART_ADDRESS;
  *p_tx_buffer++ = RECEIVE_CODE;
  *p_tx_buffer++ = RECEIVE_POTENTIOMETER_CODE;
  *p_tx_buffer++ = 0x01;
  *p_tx_buffer++ = 0x02;
  *p_tx_buffer++ = 0x02;
  *p_tx_buffer++ = 0x00;
  packageSize = 7;
  calculateCRC(packageSize);
}

void readingLM35()
{
  *p_tx_buffer++ = UART_ADDRESS;
  *p_tx_buffer++ = RECEIVE_CODE;
  *p_tx_buffer++ = RECEIVE_LM35_CODE;

  *p_tx_buffer++ = 0x01;
  *p_tx_buffer++ = 0x02;
  *p_tx_buffer++ = 0x02;
  *p_tx_buffer++ = 0x00;
  packageSize = 7;
  calculateCRC(packageSize);
}

float castToFloat()
{
  float data = 0;
  memcpy(&data, &rx_buffer[3], 4);

  return data;
}

float getLM35Data()
{
  clearData();
  readingLM35();
  uartWriting(packageSize);
  uartReading();
  castToFloat();
}

float getPotentiometerData()
{
  clearData();
  readingPotentiometer();
  uartWriting(packageSize);
  uartReading();
  castToFloat();
}
