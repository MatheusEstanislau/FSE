#include <iostream>

class Alarm {
  bool alarmState;
  bool alarmIsRinging = false;
  public:
    void disableAlarm();
    void playAlarm();
    bool getAlarmState();
    bool getAlarmisRinging();
    void setAlarmState(bool param);
};