#include <iostream>

class Alarm {
  bool alarmState;
  public:
    void disableAlarm();
    void playAlarm();
    bool getAlarmState();
    void setAlarmState(bool param);
};