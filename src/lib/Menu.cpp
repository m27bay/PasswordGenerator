#include "Menu.hpp"

Menu::Menu() {
  tabChoices = {"quit","help","create","save","print"};
  tabDesc = {
    "Quit the app",
    "Show all command",
    "Create a new password for a website",
    "Encoding and save the password in a file",
    "Print the password for a special website"
  };
}

int max(std::vector<std::string> tabString) {
  int maxSize = INT_MIN;
  for(std::string str : tabString) {
    int sizeStr = (int)str.size();
    if(sizeStr > maxSize) {
      maxSize = sizeStr;
    }
  }

  return maxSize;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

void drawLine(int sizeMax, int sizeMid) {
  std::cout << "+";
  for(size_t i=0; i<sizeMax; i++) {
    if(i == sizeMid-1) {
      std::cout << "+";
    }
    else {
      std::cout << "-";
    }
  }
  std::cout << "+\n";
}

void drawTexte(int maxChoice, std::string choice, int maxDesc, std::string desc) {
  //
  std::cout << "| " << choice;
  for(size_t i=0; i<maxChoice - (choice.size()+2); i++) {
    std::cout << " ";
  }
  std::cout << "|";
  for(size_t i=0; i<maxDesc-desc.size()-1; i++) {
    std::cout << " ";
  }
  std::cout << desc << " |\n";
}

void Menu::drawFrame() {
  std::string titleChoice = "choice";
  std::string titleDesc = "description";

  int maxChoice = max(tabChoices), maxDesc = max(tabDesc);
  maxChoice = max(maxChoice, (int)titleChoice.size()) + 3;
  maxDesc = max(maxDesc, (int)titleDesc.size()) + 4;
  int sizeFrame = maxChoice+maxDesc;

  //
  drawLine(sizeFrame, maxChoice);
  drawTexte(maxChoice, titleChoice, maxDesc, titleDesc);
  drawLine(sizeFrame, maxChoice);

  //
  for(size_t i=0; i<tabChoices.size();i++) {
    drawTexte(maxChoice, tabChoices[i], maxDesc, tabDesc[i]);
  }
  drawLine(sizeFrame, maxChoice);
}

void Menu::help() {
  drawFrame();
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
  std::cout << "Password create succesfully !\nback to the password menu." << std::endl;
}

void Menu::savePassword() {
  std::string fileName;
  std::cout << "name of the file for save (without extension): ";
  std::cin >> fileName;
  passGen.save("out/" + fileName + ".txt");
}

void Menu::run() {
  std::string choice;

  std::cout << "\nFor help, type \"help\" or \"h\"\nTo quit, type \"quit\" or \"q\"\n> ";
  std::cin >> choice;
  while(1) {
    if(choice.compare(tabChoices[0]) == 0 ||
      choice.compare(tabChoices[0].substr(0,1)) == 0)
    {
      std::cout << "bye" << std::endl;
      break;
    }
    else if(choice.compare(tabChoices[1]) == 0 ||
          choice.compare(tabChoices[1].substr(0,1)) == 0)
    {
      help();
    }
    else if(choice.compare(tabChoices[2]) == 0 ||
            choice.compare(tabChoices[2].substr(0,1)) == 0)
    {
      createPassword();
    }
    else if(choice.compare(tabChoices[3]) == 0 ||
            choice.compare(tabChoices[3].substr(0,1)) == 0)
    {
      savePassword();
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