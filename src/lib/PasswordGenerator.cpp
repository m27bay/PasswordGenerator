#include <iostream>
#include <fstream> // For write/read in a file

#include <string>

#include "PasswordGenerator.hpp"

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
int PasswordGenerator::intAlea(int max, int min) {
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
  int sizePassword = sizeMin + intAlea(sizeMax, sizeMin);
  for(size_t i=0; i<sizePassword; i++) {
    int alea = intAlea(1, 10);
    if(alea < 7) {
      password += lowerCharAlea();
    } 
    else if(alea < 2) {
      password += std::to_string(intAlea(1, 9));
    }
    else if(alea < 2) {
      password += specialCharAlea();
    }
    else if(alea < 4) {
      password += upperCharAlea();
    }
  }
}

void PasswordGenerator::write(std::string fileName) {
  // Empty
}

void PasswordGenerator::print() {
  std::cout << "size min : " << sizeMin << std::endl;
  std::cout << "size max : " << sizeMax << std::endl;
  if(password.size() == 0) {
    std::cout << webSite << " : not defined" << std::endl;
  }
  else {
    std::cout << webSite << " : " << password << std::endl;
  }
}

/* Destructor */
PasswordGenerator::~PasswordGenerator() {
  // Empty
}
