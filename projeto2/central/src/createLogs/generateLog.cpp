#include "../../inc/generateLog.hpp"
#include <iostream>
using namespace std;

void initWrite()
{
  FILE *f = fopen("logs/project2.csv", "w");
  fprintf(f, "Command, Alarm, AlarmRinging, Date, Hour\n");
  fclose(f);
}

void writeInCsv(int command, bool alarm, bool alarmRiging)
{
  string stringCommand;
  string stringAlarm;
  string stringAlarmRinging;
  switch (command)
  {
    case 1:
      stringCommand = "Turn on Lamp 1";
      break;
    case 2:
      stringCommand = "Turn on Lamp 2";
      break;
    case 3:
      stringCommand = "Turn on Lamp 3";
      break;
    case 4:
      stringCommand = "Turn on Lamp 4";
      break;
    case 5:
      stringCommand = "Turn on air conditioner 1";
      break;
    case 6:
      stringCommand = "Turn on air conditioner 2";
      break;
    case 7:
      stringCommand = "Turn off lamp 1";
      break;
    case 8:
      stringCommand = "Turn off lamp 2";
      break;
    case 9:
      stringCommand = "Turn off lamp 3";
      break;
    case 10:
      stringCommand = "Turn off lamp 4";
      break;
    case 11:
      stringCommand = "Turn off air conditioner 1";
      break;
    case 12:
      stringCommand = "Turn off air conditioner 1";
      break;
    case 13:
      stringCommand = "Turn on Alarm";
      break;
    case 14:
      stringCommand = "Turn off Alarm";
      break;
    case 15:
      stringCommand = "View All States";
      break;
    case 16:
      stringCommand = "Play alarm";
      break;
    case 17:
      stringCommand = "Stop ringing alarm";
      break;   
    default:
      break;
  }
  alarm == true ? stringAlarm = "Alarm activated" : stringAlarm = "Alarm off";
  alarmRiging == true ? stringAlarmRinging = "Playing" : stringAlarmRinging = "Not Playing";
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  FILE *f = fopen("logs/project2.csv", "a");
  fprintf(f, "%s, %s, %s, %d/%d/%d, %.2d:%.2d:%.2d\n",stringCommand.c_str(), stringAlarm.c_str(), stringAlarmRinging.c_str(), tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fclose(f);
}