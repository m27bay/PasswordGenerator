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
  PasswordGenerator(int sizeMini, int sizeMaxi, std::string newWebSite);

  /* Functions */
  int intAlea(int max, int min);
  char lowerCharAlea();
  char upperCharAlea();
  char specialCharAlea();
  void passwordGenerate();
  void write(std::string fileName);
  void print();

  /* Destructor */
  ~PasswordGenerator();
};
