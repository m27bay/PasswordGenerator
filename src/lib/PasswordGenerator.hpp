#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

class PasswordGenerator
{
private:
  /* data */
  int sizeMin, sizeMax;
  std::string password;
  std::string webSite;

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

  void save(std::string);
  void resetFile(std::string);
  
  void print();

  /* Destructor */
  ~PasswordGenerator();
};

#endif