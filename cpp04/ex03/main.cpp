#include "Cure.hpp"
#include "Ice.hpp"

int main() {
  Ice ice;
  AMateria *p;
  p = ice.clone();
  std::cout << p->getType() << std::endl;

  Ice copy(ice);
  std::cout << copy.getType() << std::endl;
  return 0;
}
