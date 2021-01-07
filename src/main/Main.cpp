#include <iostream>

#include <ctime>

#include "../lib/PasswordGenerator.hpp"

int main(void) {
  srand((int)time(0));
  PasswordGenerator p(8, 15, "google");
  p.passwordGenerate();
  p.print();
  p.save("out/save.txt");
  return 0;
}
