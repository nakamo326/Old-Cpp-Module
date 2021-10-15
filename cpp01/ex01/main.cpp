#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
  Zombie* h;
  int n = 5;

  h = zombieHorde(n, "John");

  for (int i = 0; i < n; i++) {
    h[i].announce();
  }

  delete[] h;

  return 0;
}
