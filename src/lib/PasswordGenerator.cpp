#include "PasswordGenerator.hpp"
#include "Parser.hpp"
#include "Tree.hpp"
#include "Writer.hpp"

std::string specialChar = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";

/* Constructor */
PasswordGenerator::PasswordGenerator() {
  sizeMax = sizeMin = -1;
  webSite = "\0";
  password = "\0";
}

PasswordGenerator::PasswordGenerator(int sizeMini, int sizeMaxi, std::string newWebSite) {
  sizeMax = sizeMaxi;
  sizeMin = sizeMini;
  webSite = newWebSite;
  password = "\0";
}

/* Functions */
int PasswordGenerator::intAlea(int min, int max) {
  return rand()%(max-min) + min;
}

char PasswordGenerator::lowerCharAlea() {
  return (char)intAlea((int)'a', (int)'z');
}

char PasswordGenerator::upperCharAlea() {
  return (char)intAlea((int)'A', (int)'Z');
}

char PasswordGenerator::specialCharAlea() {
  return specialChar[intAlea(0, (int)specialChar.size()-1)];
}

void PasswordGenerator::passwordGenerate() {
  int sizePassword = sizeMin + intAlea(sizeMin, sizeMax);
  bool haveInteger = false, haveSpecialChar = false, haveUpperChar = false;
  for(size_t i=0; i<sizePassword; i++) {
    int alea = intAlea(1, 20);
    if(7 < alea && alea <= 17) {
      password += lowerCharAlea();
    } 
    else if(0 < alea && alea <= 4) {
      password += std::to_string(intAlea(1, 9));
      haveInteger = true;
    }
    else if(4 < alea && alea <= 7) {
      password += specialCharAlea();
      haveSpecialChar = true;
    }
    else if(alea > 17) {
      password += upperCharAlea();
      haveUpperChar = true;
    }
  }

  if(!haveInteger) {
    password += std::to_string(intAlea(1, 9));
    haveInteger = true;
    sizePassword++;
  }
  if(!haveSpecialChar) {
    password += specialCharAlea();
    haveSpecialChar = true;
    sizePassword++;
  }
  if(!haveUpperChar) {
    password += upperCharAlea();
    haveUpperChar = false;
    sizePassword++;
  }
}

int PasswordGenerator::save(std::string fileName) {
  std::ofstream flux;
  flux.open(fileName, std::ios::out | std::ios::trunc);
  if(flux) {
      flux << webSite << " : " << password << "\n";
      flux.close();
      return 0;
  }
  else {
      std::cout << "ERROR : can't open '" << fileName << "'\n";
      return 1;
  }
}

int PasswordGenerator::resetFile(std::string fileName) {
  std::ofstream flux;
  flux.open(fileName, std::ios::out | std::ios::trunc);
  if(flux) {
      flux << "\0";
      flux.close();
      return 0;
  }
  else {
      std::cout << "ERROR : can't open '" << fileName << "'\n";
      return 1;
  }
}

void PasswordGenerator::print() {
  if(password.size() == 0) {
    std::cout << webSite << " : not defined" << std::endl;
  }
  else {
    std::cout << webSite << " : " << password << std::endl;
  }
}

/* Getters */
std::string PasswordGenerator::getPassword() {
  return password;
}

/* Destructor */
PasswordGenerator::~PasswordGenerator() {
  // Empty
}
