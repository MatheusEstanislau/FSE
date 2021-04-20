#include "../../inc/alarmHandler.hpp"
#include "../../inc/generateLog.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

void Alarm::playAlarm()
{
  int temp;
  cout << "Triggering alarm" << endl;
  auto finish = system_clock::now() + 30s;
  while (alarmState)
  {
    while (system_clock::now() < finish)
    {
      system("omxplayer alarm.mp3 > /dev/null");
    }
    cout << "Enter 1 to disable the alarm" << endl;
    cin >> temp;
    switch (temp)
    {
    case 1:
      alarmState = 0;
      writeInCsv(14, alarmState);
      break;
    default:
      finish = system_clock::now() + 30s;
      break;
    }
  }
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