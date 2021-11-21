#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Color.hpp"

Base *generate(void) {
  Base *ptr = NULL;
  std::srand(std::time(NULL));
  int r = std::rand() % 3;
  if (r == 0) {
    std::cout << "generated A" << std::endl;
    ptr = new A;
  } else if (r == 1) {
    std::cout << "generated B" << std::endl;
    ptr = new B;
  } else if (r == 2) {
    std::cout << "generated C" << std::endl;
    ptr = new C;
  }
  return ptr;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A" << std::endl;
  if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B" << std::endl;
  if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (const std::bad_cast &) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    } catch (const std::bad_cast &) {
      try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
      } catch (const std::bad_cast &) {
        std::cout << "failed to cast" << std::endl;
      }
    }
  }
}

int main() {
  Base *bp = generate();
  Base &bref = *bp;
  std::cout << BLU "void identify(Base* p);" NC << std::endl;
  identify(bp);
  std::cout << YLW "void identify(Base& p);" NC << std::endl;
  identify(bref);

  return 0;
}
