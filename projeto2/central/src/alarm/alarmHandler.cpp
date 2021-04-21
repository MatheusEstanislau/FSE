#include "../../inc/alarmHandler.hpp"
#include "../../inc/generateLog.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

void Alarm::playAlarm()
{
  int temp;
  cout << "Triggering alarm" << endl;
  while (alarmState)
  {
    system("omxplayer alarm.mp3 > /dev/null");
  }
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

void Alarm::setAlarmState(bool param)
{
  alarmState = param;
}