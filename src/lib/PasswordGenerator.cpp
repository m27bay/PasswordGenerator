#include <iostream>
#include <fstream> // For write/read in a file

#include <string>

#include <random>
#include <chrono> // Pour chrono::system_clock
#include <functional> // Pour bind

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
int PasswordGenerator::intAlea(int min, int max) {
  return rand()%(max-min) + min;
}

int PasswordGenerator::intAlea2(int min, int max) {
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> distrib(min, max);
  auto rd = bind(distrib, re);
  return rd();
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

void PasswordGenerator::resetFile(std::string fileName) {
  std::ofstream flux;
  flux.open(fileName, std::ios::out | std::ios::trunc);
  if(flux) {
      flux << "\0";
      flux.close();
  }
  else {
      std::cout << "ERROR : can't open '" << fileName << "'\n";
  }
}

void PasswordGenerator::save(std::string fileName) {
  std::ofstream flux;
  flux.open(fileName, std::ios::out | std::ios::app);
  if(flux) {
      flux << webSite << " : " << password << "\n";
      flux.close();
  }
  else {
      std::cout << "ERROR : can't open '" << fileName << "'\n";
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

/* Destructor */
PasswordGenerator::~PasswordGenerator() {
  // Empty
}
