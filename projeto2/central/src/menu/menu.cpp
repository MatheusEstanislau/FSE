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
  if(option < 1 || option > 15) 
  {
    cout << "Invalid Option" << endl;
    displayMenu();
  }
  else
  {
    command = option;
  }
}

int Menu::getCommand(){
  return command;
}