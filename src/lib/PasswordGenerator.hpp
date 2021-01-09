#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

#include <iostream>
#include <fstream> // For write/read in a file
#include <ctime>

#include <climits>

#include <string>
#include <vector>
#include <map>

class PasswordGenerator
{
private:
  /* data */
  int sizeMin, sizeMax;
  std::string webSite;
  std::string password;

public:
  /* Constructor */
  PasswordGenerator();
  PasswordGenerator(int, int, std::string);

  /* Functions */
  int intAlea(int, int);
  int intAlea2(int, int);
  char lowerCharAlea();
  char upperCharAlea();
  char specialCharAlea();

  void passwordGenerate();

  int save(std::string);
  int resetFile(std::string);
  
  void print();

  /* Getter */
  std::string getPassword();

  /* Destructor */
  ~PasswordGenerator();
};

#endif