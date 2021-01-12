#ifndef MENU_HPP
#define MENU_HPP

#include "PasswordGenerator.hpp"

class Menu
{
private:
  /* data */
  PasswordGenerator passGen;
  
  std::vector<std::string> tabChoices;
  std::vector<std::string> tabDesc;
  std::string saveFile = "out/save.txt";

public:
  /* Constructor */
  Menu();

  /* Functions */
  void run();

  void help();
  void drawFrame();

  void createPassword();
  void savePassword();
  void resetFile();

  /* Destructor */
  ~Menu();
};

#endif