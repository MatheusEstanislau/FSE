#include "../../inc/menu.hpp"

void Menu::displayMenu()
{
  cout << endl;
  cout << "Welcome to your home automation App" << endl;
  cout << endl;
  cout << "Press 1 to turn on the lamp 1, Press 7 to turn off" << endl;
  cout << "Press 2 to turn on the lamp 2, Press 8 to turn off" << endl;
  cout << "Press 3 to turn on the lamp 3, Press 9 to turn off" << endl;
  cout << "Press 4 to turn on the lamp 4, Press 10 to turn off" << endl;
  cout << "Press 5 to turn on the air conditioner 1, Press 11 to turn off" << endl;
  cout << "Press 6 to turn on the air conditioner 2, Press 12 to turn off" << endl;
  cout << endl;
  cout << "Press 13 to turn on the alarm, Press 14 to turn off" << endl;
  cout << endl;
  cout << "Press 15 view all states" << endl;
  cout << endl;
  cout << "Press ctrl + c close program" << endl;
  cin >> option;
  switch (option)
  {
  case 1:
    command = 1;
    break;
  case 2:
    command = 2;
    break;
  case 3:
    command = 3;
    break;
  case 4:
    command = 4;
    break;
  case 5:
    command = 5;
    break;
  case 6:
    command = 6;
    break;
  case 7:
    command = 7;
    break;
  case 8:
    command = 8;
    break;
  case 9:
    command = 9;
    break;
  case 10:
    command = 10;
    break;
  case 11:
    command = 11;
    break;
  case 12:
    command = 12;
    break;
  case 13:
    command = 13;
    break;
  case 14:
    command = 14;
    break;
  case 15:
    command = 15;
    break;
  default:
    cout << "Invalid Option" << endl;
    displayMenu();
    break;
  }
}

int Menu::getCommand()
{
  return command;
}