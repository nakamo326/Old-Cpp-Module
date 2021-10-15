#include "Pony.hpp"

void ponyOnTheHeap() {
  Pony *heap;

  heap = new Pony("Pony on Heap");
  std::cout << &(*heap) << std::endl;
  heap->cry();
  heap->run();
  delete heap;
}

void ponyOnTheStack() {
  Pony stack("stack");
  std::cout << &stack << std::endl;
  stack.cry();
  stack.run();
}

int main() {
  ponyOnTheHeap();
  ponyOnTheStack();
  return 0;
}
