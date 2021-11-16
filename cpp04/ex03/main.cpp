#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

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

  MateriaSource ms;
  ms.learnMateria(NULL);
  ms.learnMateria(m);
  ms.learnMateria(m);
  ms.learnMateria(m2);
  ms.learnMateria(m2);
  ms.learnMateria(m2);

  MateriaSource ms2(ms);
  ms2 = ms;

  delete m;
  delete m2;

  m = ms.createMateria("ice");
  m->use(kuraudo);
  delete m;
  return 0;
}
