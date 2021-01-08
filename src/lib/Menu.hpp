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
  Menu(/* args */);

  /* Functions */
  void run();

  /* Destructor */
  ~Menu();
};

#endif