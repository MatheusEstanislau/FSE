#include "../../inc/alarmHandler.hpp"
#include "../../inc/generateLog.hpp"
#include <chrono>

using namespace std;

void Alarm::playAlarm()
{
  int temp;
  cout << "Triggering alarm" << endl;
  cout << "Open menu to turn off the alarm" << endl;
  alarmIsRinging = true;
  writeInCsv(16, alarmState, true);
  while (alarmState)
  {
    system("omxplayer alarm.mp3 > /dev/null");
  }
  alarmIsRinging = false;
  writeInCsv(17, alarmState, false);
  cout << "Alarm Off" << endl;
}

void Alarm::disableAlarm()
{
  alarmState = false;
}

bool Alarm::getAlarmState()
{
  return alarmState;
}

bool Alarm::getAlarmisRinging()
{
  return alarmIsRinging;
}

void Alarm::setAlarmState(bool param)
{
  alarmState = param;
}