#include <iostream>

#include <string>

#include "Menu.hpp"
#include "PasswordGenerator.hpp"

Menu::Menu() {
  // Empty
}

void Menu::help() {
  std::cout << "passeword -- go to the password menu." << std::endl;
}

void Menu::helpPassword() {
  std::cout << "create -- create a new password for a website." << std::endl;
  std::cout << "save -- encoding and save the password in a file." << std::endl;
  std::cout << "show -- show the password for a special website." << std::endl;
}

void Menu::createPassword() {
  int sizePasswordMin, sizePasswordMax;
  std::string webSite;

  std::cout << "Need some informations for create the passeword : " << std::endl;
  std::cout << "Size min : ";
  std::cin >> sizePasswordMin;
  std::cout << "Size max : ";
  std::cin >> sizePasswordMax;
  std::cout << "Website : ";
  std::cin >> webSite;
  
  PasswordGenerator passGen(sizePasswordMin, sizePasswordMax, webSite);
  passGen.passwordGenerate();
  std::cout << "Password create succesfully !\back to the password menu." << std::endl;
}

void Menu::savePassword() {
  std::string fileName;
  std::cout << "name of the file for save (without extension): ";
  std::cin >> fileName;
  passGen.save("../out/" + fileName + ".txt");
}

void Menu::menuPassword() {
  std::string choice;

  std::cout << "\nFor help, type \"help\" or \"h\"\nFor back to the menu, type \"back\" or \"b\"\n> ";
  std::cin >> choice;
  while(1) {
    if(choice.compare("back") == 0 || choice.compare("b") == 0) {
      std::cout << "back" << std::endl;
      std::cout << "\nFor help, type \"help\" or \"h\"\nTo quit, type \"quit\" or \"q\"\n";
      break;
    }
    else if(choice.compare("help") == 0 || choice.compare("h") == 0) {
      helpPassword();
    }
    else if(choice.compare("create") == 0 || choice.compare("c") == 0) {
      createPassword();
    }
    else if(choice.compare("save") == 0 || choice.compare("s") == 0) {
      savePassword();
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
      menuPassword();
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