#include <iostream>
#include <fstream> // For write/read in a file

#include <string>

#include "PasswordGenerator.hpp"

std::string specialChar = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";

/* Constructor */
PasswordGenerator::PasswordGenerator() {
  sizeMax = sizeMin = -1;
}

PasswordGenerator::PasswordGenerator(int sizeMini, int sizeMaxi) {
  sizeMax = sizeMaxi;
  sizeMin = sizeMini;
}

/* Functions */
int PasswordGenerator::intAlea(int max, int min) {
  return rand()%(max-min) + min;
}

char PasswordGenerator::charAlea() {
  return (char)intAlea((int)'a', (int)'z');
}

char PasswordGenerator::specialCharAlea() {
  return specialChar[intAlea(0, (int)specialChar.size()-1)];
}

std::string PasswordGenerator::passwordGener() {
  std::string password = "\0";
  int sizePassword = sizeMin + intAlea(sizeMax, sizeMin);
  for(size_t i=0; i<sizePassword; i++) {
    int alea = intAlea(1, 10);
    if(alea%2) {
      password += charAlea();
    } 
    else if()
  }
}

void PasswordGenerator::write(std::string fileName) {

}

/* Destructor */
PasswordGenerator::~PasswordGenerator() {

}
