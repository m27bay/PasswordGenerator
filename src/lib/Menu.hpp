#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu
{
private:
  /* data */
  PasswordGenerator passGen;

public:
  /* Constructor */
  Menu();

  /* Functions */
  void run();

  void help();

  void menuPassword();
  void helpPassword();
  void createPassword();
  void savePassword();

  /* Destructor */
  ~Menu();
};

#endif