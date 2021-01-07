#include <iostream>

#include <ctime>

#include "../lib/PasswordGenerator.hpp"

#define FILE "out/save.txt"

int main(void) {
  srand((int)time(0));
  PasswordGenerator p(8, 15, "google");
  p.passwordGenerate();
  p.print();
  // p.resetFile(FILE);
  p.save(FILE);
  return 0;
}
