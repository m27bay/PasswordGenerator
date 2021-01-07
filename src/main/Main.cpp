#include <iostream>

#include "../lib/PasswordGenerator.hpp"

int main(int argc, char const *argv[]) {
  PasswordGenerator p(8, 15, "google");
  p.passwordGenerate();
  p.print();
  return 0;
}
