#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  Cure cure;
  Ice ice;

  Cure copy(cure);
  std::cout << copy.getType() << std::endl;
  Ice copy1(ice);
  std::cout << copy1.getType() << std::endl;

  AMateria *m = cure.clone();
  std::cout << m->getType() << std::endl;
  AMateria *m2 = ice.clone();
  std::cout << m2->getType() << std::endl;

  MateriaSource ms;
  ms.learnMateria(NULL);
  ms.learnMateria(m);
  ms.learnMateria(m);
  ms.learnMateria(m2);
  ms.learnMateria(m2);
  ms.learnMateria(m2);

  MateriaSource ms2(ms);
  ms2 = ms;

  Character kuraudo("†kuraudo†");
  std::cout << kuraudo.getName() << std::endl;
  Character nameless;
  nameless = kuraudo;

  kuraudo.equip(m);
  kuraudo.equip(m2);
  kuraudo.unequip(0);
  kuraudo.unequip(1);
  kuraudo.unequip(2);
  delete m;
  delete m2;

  kuraudo.equip(NULL);
  kuraudo.equip(ms.createMateria("ice"));
  kuraudo.equip(ms.createMateria("ice"));
  kuraudo.equip(ms.createMateria("fire"));
  kuraudo.equip(ms.createMateria("cure"));
  kuraudo.equip(ms.createMateria("cure"));
  AMateria *rest = ms.createMateria("cure");
  kuraudo.equip(rest);
  delete rest;
  Character sephiroth("Sephiroth");
  kuraudo.use(-1, sephiroth);
  kuraudo.use(0, sephiroth);
  kuraudo.use(1, sephiroth);
  kuraudo.use(2, sephiroth);
  kuraudo.use(3, sephiroth);
  kuraudo.use(4, sephiroth);

  return 0;
}
