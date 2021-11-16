#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
  Ice ice;
  Cure cure;
  AMateria *m;
  AMateria *m2;

  Ice copy(ice);
  std::cout << copy.getType() << std::endl;
  Cure copy1(cure);
  std::cout << copy1.getType() << std::endl;

  m = cure.clone();
  std::cout << m->getType() << std::endl;
  m2 = ice.clone();
  std::cout << m2->getType() << std::endl;

  Character kuraudo("†kuraudo†");
  std::cout << kuraudo.getName() << std::endl;
  Character nameless;
  nameless = kuraudo;
  kuraudo.equip(NULL);
  kuraudo.equip(m);
  kuraudo.equip(m);
  kuraudo.equip(m2);
  kuraudo.equip(m2);
  kuraudo.equip(m2);
  kuraudo.unequip(3);
  kuraudo.unequip(3);
  Character sephiroth("Sephiroth");
  kuraudo.use(0, sephiroth);
  kuraudo.use(2, sephiroth);
  kuraudo.use(3, sephiroth);

  delete m;
  delete m2;
  return 0;
}
