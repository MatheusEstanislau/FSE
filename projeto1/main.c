#include <stdio.h>
#include <stdlib.h>
#include "bme280/bme280.h"
#include "uartModBus/uart.h"
#include <unistd.h>
#include "i2c/i2c.h"
#include "pwm/wiringPi.h"
#include "pid/pid.h"
#include "file/writeCsv.h"
#include <signal.h>

void poweroff()
{
  disableCooler();
  disableResistor();
  printf("\nDesligando Sistema\n");
  exit(0);
}

void waitFunction()
{
  alarm(1);
}

int main(int argc, char const *argv[])
{
  wiringPiSetup();
  initWrite();
  initializeUart();
  pid_configura_constantes(5.0, 1.0, 5.0);
  int initialize;
  float potentiometer, lm35;
  int Temperature, Pressure, Humidity;
  initialize = bme280Init(1, 0x76);

  while (1)
  {
    alarm(1);
    signal(SIGINT, poweroff);
    signal(SIGALRM, waitFunction);
    potentiometer = getPotentiometerData();
    lm35 = getLM35Data();
    bme280ReadValues(&Temperature, &Pressure, &Humidity);
    pid_atualiza_referencia(potentiometer);

    double controle = pid_controle(lm35);

    printf("%f\n", controle);
    if (controle > 0)
    {
      activateResistor(controle);
      disableCooler();
    }
    else if (controle < -40)
    {
      activateCooler((controle * -1));
      disableResistor();
    }
    printf("Text = %.2f ºC, Tint. = %.2f%%  Tref = %.2f\n", (float)Temperature / 100, lm35, potentiometer);
    writeInLcd(potentiometer, lm35, (float)Temperature / 100);
    writeInCsv((float)Temperature / 100, (float)lm35, (float)potentiometer);
    pause();
  }
  return 0;
}
