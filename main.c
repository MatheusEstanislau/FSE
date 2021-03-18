#include <stdio.h>
#include "bme280/bme280.h"
#include "uartModBus/uart.h"
#include <unistd.h>
#include "i2c/i2c.h"

int main(int argc, char const *argv[])
{
  int initialize;
  float potentiometer, lm35;
  int Temperature, Pressure, Humidity;
  initialize = bme280Init(1, 0x76);
  if (initialize != 0)
  {
    printf("Não foi possível inicializar\n");
    return -1;
  }

  initializeUart();
  int flag;
  while (1)
  {
    potentiometer = getPotentiometerData();
    lm35 = getLM35Data();
    // printf("LM35 Sensor: %.2f ºC\n", lm35);
    // printf("Potentiometer: %.2f ºC\n", potentiometer);
    bme280ReadValues(&Temperature, &Pressure, &Humidity);
    // printf("Calibrated temp. = %3.2f C, hum. = %2.2f%%\n", (float)Temperature/100, (float)Humidity / 1024.0);
    writeInLcd(potentiometer,lm35, (float)Temperature/100 );
    sleep(1);
  }
  return 0;
}
