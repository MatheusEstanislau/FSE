#include <iostream>

using namespace std;

class Menu
{
  int command;
  int option;
  public:
    void displayMenu(bool alarmSate);
    int getCommand();
};