#include <iostream>

#include <ctime>
#include <string>
#include <string.h>

#include "../lib/PasswordGenerator.hpp"
#include "../lib/Menu.hpp"

int main(void) {
  Menu menu;
  menu.run();
  // if(argc == 3 && strcmp(argv[2], "resetFile:yes") == 0) {
  //   PasswordGenerator p;
  //   p.resetFile(FILE);

  //   srand((int)time(0));
  //   p(8, 15, argv[1]);
  //   p.passwordGenerate();
  //   // p.print();
  //   p.save(FILE);
  // }
  // else if(argc == 2) {
  //   srand((int)time(0));
  //   PasswordGenerator p(8, 15, argv[1]);
  //   p.passwordGenerate();
  //   // p.print();
  //   p.save(FILE);
  // }
  // else {
  //   std::cout << "Usage : ./exe webSite resetFile:no(default)\n    or ./exe webSite resetFile:yes" << std::endl;
  //   return 1;
  // }

  return 0;
}
