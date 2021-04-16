#include "menu.hpp"

void Menu::displayMenu()
{
  cout << "Welcome to your home automation App" << endl;
  cout << "Press 1 to to turn on the lamp 1" << endl;
  cout << "Press 2 to to turn on the lamp 2" << endl;
  cout << "Press 3 to turn on the lamp 3" << endl;
  cout << "Press 4 to turn on the lamp 4" << endl;
  cout << "Press 5 to to turn off the lamp 1" << endl;
  cout << "Press 6 to to turn off the lamp 2" << endl;
  cout << "Press 7 to turn off the lamp 3" << endl;
  cout << "Press 8 to turn off the lamp 4" << endl;
  cout << "Press 9 to turn on the air conditioner 1" << endl;
  cout << "Press 10 to turn on the air conditioner 2" << endl;
  cout << "Press 11 to turn off the air conditioner 1" << endl;
  cout << "Press 12 to turn off the air conditioner 2" << endl;
  cout << "Press 13 close program" << endl;
  cin >> option;
  if(option < 1 || option > 13) 
  {
    cout << "Invalid Option" << endl;
    displayMenu();
  }
  else if(option == 13) 
  {
    cout << "Finished program" << endl;
    exit(0);
  }
  else
  {
    command = option;
  }
}

int Menu::getCommand(){
  return command;
}