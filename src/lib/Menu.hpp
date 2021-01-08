#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu
{
private:
  /* data */
  std::string tmpPassword;
  bool passwordSave = false;

public:
  /* Constructor */
  Menu();

  /* Functions */
  void run();

  void help();

  void menuPassword();
  void helpPassword();
  void create()

  /* Destructor */
  ~Menu();
};

#endif