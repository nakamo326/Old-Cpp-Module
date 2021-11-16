#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
  Ice ice;
  Cure cure;
  AMateria *p;

  Ice copy(ice);
  std::cout << copy.getType() << std::endl;
  Cure copy1(cure);
  std::cout << copy1.getType() << std::endl;

  p = ice.clone();
  std::cout << p->getType() << std::endl;
  delete p;

  p = cure.clone();
  std::cout << p->getType() << std::endl;

  Character kuraudo("†kuraudo†");
  std::cout << kuraudo.getName() << std::endl;
  Character nameless;
  nameless = kuraudo;
  kuraudo.equip(NULL);
  kuraudo.equip(p);
  p = ice.clone();
  kuraudo.equip(p);
  kuraudo.equip(p);
  kuraudo.equip(p);
  kuraudo.equip(p);
  kuraudo.unequip(3);
  kuraudo.unequip(3);
  Character sephiroth("Sephiroth");
  kuraudo.use(0, sephiroth);
  kuraudo.use(2, sephiroth);
  kuraudo.use(3, sephiroth);

  return 0;
}
