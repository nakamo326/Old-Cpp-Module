#include "serialization.hpp"

uintptr_t serialize(Data* ptr) {
  std::srand(std::time(NULL));
  ptr->num0 = std::rand() % 64;
  ptr->num1 = std::rand() % 64;
  std::cout << ptr->num0 << std::endl;
  std::cout << ptr->num1 << std::endl;

  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int main() {
  Data* ptr = new Data;
  std::cout << "sizeof(Data): " << sizeof(Data) << std::endl;
  uintptr_t serialized = serialize(ptr);
  Data* des = deserialize(serialized);
  std::cout << des->num0 << std::endl;
  std::cout << des->num1 << std::endl;
  return 0;
}
