#include <iostream>

#include <string>

#include "Menu.hpp"

Menu::Menu() {
  // Empty
}

void help() {
  std::cout << "passeword -- go to the password menu." << std::endl;
}

void helpPassword() {
  std::cout << "create -- create a new password for a website." << std::endl;
  std::cout << "save -- encoding and save the password in a file." << std::endl;
  std::cout << "show -- show the password for a special website." << std::endl;
}

void create() {
  
}

void password() {
  std::string choice;

  std::cout << "\nFor help, type \"help\" or \"h\"\nFor back to the menu, type \"back\" or \"b\"\n> ";
  std::cin >> choice;
  while(1) {
    if(choice.compare("back") == 0 || choice.compare("b") == 0) {
      std::cout << "back" << std::endl;
      break;
    }
    else if(choice.compare("help") == 0 || choice.compare("h") == 0) {
      helpPassword();
    }
    else if(choice.compare("create") == 0 || choice.compare("c") == 0) {
      create();
    }
    else {
      std::cout << "unknown choice" << std::endl;
    }
    std::cout << "> ";
    std::cin >> choice;
  }
  
}

void Menu::run() {
  std::string choice;

  std::cout << "\nFor help, type \"help\" or \"h\"\nTo quit, type \"quit\" or \"q\"\n> ";
  std::cin >> choice;
  while(1) {
    if(choice.compare("quit") == 0 || choice.compare("q") == 0) {
      std::cout << "bye" << std::endl;
      break;
    }
    else if(choice.compare("help") == 0 || choice.compare("h") == 0) {
      help();
    }
    else if(choice.compare("password") == 0 || choice.compare("p") == 0) {
      password();
    }
    else {
      std::cout << "unknown choice" << std::endl;
    }
    std::cout << "> ";
    std::cin >> choice;
  }
}

Menu::~Menu() {
  // Empty
}