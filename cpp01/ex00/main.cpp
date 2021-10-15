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
  std::cout << "call ponyOnTheHeap" << std::endl;
  ponyOnTheHeap();
  std::cout << "call ponyOnTheStack" << std::endl;
  ponyOnTheStack();
  std::cout << "done" << std::endl;
  return 0;
}
