#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "bme280/bme280.h"
#include "uartModBus/uart.h"
#include "i2c/i2c.h"
#include "pwm/wiringPi.h"
#include "pid/pid.h"
#include "file/writeCsv.h"

float cooler;
float resistor;
int writeCounter = 0;
float userTemperature;
float referenceTemperature = 0;
float potentiometer, lm35;
int switchMode = 0;
void poweroff()
{
  printf("\nDesligando Sistema\n");
  disableCooler();
  disableResistor();
  ClrLcd();
  printf("...Sistema Desligado\n");
  exit(0);
}

void waitFunction()
{
  alarm(1);
  if (writeCounter == 2)
  {
    writeCounter = 0;
  }
  writeCounter++;
}

void userInsertStop()
{

  printf("\nQual modo de referência deseja utilizar?\n");
  printf("Digite 0, para potenciometro\n");
  printf("Digite 1 para entrar com sua temperatura\n");
  scanf("%d", &switchMode);
  switch (switchMode)
  {
  case 0:
    printf("Modo escolhido: Potenciometro\n");
    referenceTemperature = potentiometer;
    break;
  case 1:
    printf("\nInsira a temperatura desejada: \n");
    scanf("%f", &userTemperature);
    printf("Alterando para temperatura escolhida: %f\n", userTemperature);
  default:
    break;
  }
}

int main(int argc, char const *argv[])
{
  int initialize;

  int Temperature, Pressure, Humidity;
  wiringPiSetup();
  initWrite();
  initializeUart();
  pid_configura_constantes(5.0, 1.0, 5.0);
  initialize = bme280Init(1, 0x76);
  signal(SIGINT, poweroff);
  signal(SIGALRM, waitFunction);
  alarm(1);
  while (1)
  {
    signal(SIGTSTP, userInsertStop);
    potentiometer = getPotentiometerData();
    if (switchMode == 0)
    {
      referenceTemperature = potentiometer;
    }
    else
    {
      referenceTemperature = userTemperature;
    }
    lm35 = getLM35Data();
    bme280ReadValues(&Temperature, &Pressure, &Humidity);
    pid_atualiza_referencia(referenceTemperature);

    double controle = pid_controle(lm35);

    if (controle > 0)
    {
      activateResistor(controle);
      disableCooler();
      resistor = controle;
      cooler = 0;
    }
    else if (controle < -40)
    {
      activateCooler((controle * -1));
      disableResistor();
      cooler = controle;
      resistor = 0;
    }
    else
    {
      disableCooler();
      disableResistor();
    }
    printf("\n|-----------------------------------------------------------|\n");
    printf("|                                                           |\n");
    printf("|     Text = %.2f ºC, Tint. = %.2f ºC  Tref = %.2f ºC    |\n", (float)Temperature / 100, lm35, referenceTemperature);
    printf("|         Uso cooler: %.2f %% Uso Resistor: %.2f %%         |\n", cooler, resistor);
    printf("|  digite: ctrl + z para alterar modo de temperatura        |\n");
    if (switchMode == 0)
    {
      printf("|              Referencia: Potenciometro                     |\n");
    }
    else
    {
      printf("|                  Referencia: Usuario                         |\n");
    }
    printf("|            Digite: ctrl + c para encerrar                 |\n");
    printf("|-----------------------------------------------------------|\n");
    writeInLcd(referenceTemperature, lm35, (float)Temperature / 100);
    if (writeCounter == 2)
    {
      writeInCsv((float)Temperature / 100, (float)lm35, (float)referenceTemperature, cooler, resistor);
    }
    pause();
  }
  return 0;
}