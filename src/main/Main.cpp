#include "../lib/PasswordGenerator.hpp"
#include "../lib/Menu.hpp"

int main(void) {
  srand(time(NULL));
  Menu menu;
  menu.run();

  return 0;
}
