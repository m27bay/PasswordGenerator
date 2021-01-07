class PasswordGenerator
{
private:
  /* data */
  int sizeMin, sizeMax;

public:
  /* Constructor */
  PasswordGenerator();
  PasswordGenerator(int sizeMini, int sizeMaxi);

  /* Functions */
  int intAlea(int max, int min);
  char charAlea();
  char specialCharAlea();
  std::string passwordGener();
  void write(std::string fileName);

  /* Destructor */
  ~PasswordGenerator();
};
