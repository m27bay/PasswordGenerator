#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

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

  void save(std::string);
  void resetFile(std::string);
  
  void print();

  /* Getter */
  std::string getPassword();

  /* Destructor */
  ~PasswordGenerator();
};

#endif