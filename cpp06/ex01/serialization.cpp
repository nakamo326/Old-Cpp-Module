#include "serialization.hpp"

void init_data(Data* ptr) {
  char table[17] = {"0123456789ABCDEF"};
  std::srand(std::time(NULL));

  for (size_t i = 0; i < 7; i++) {
    ptr->c0[i] = table[std::rand() % 16];
  }
  ptr->c0[7] = '\0';
  ptr->num = std::rand() % 1000;
  for (size_t i = 0; i < 7; i++) {
    ptr->c1[i] = table[std::rand() % 16];
  }
  ptr->c1[7] = '\0';

  std::cout << CYN "--initialized data--" NC << std::endl
            << "c0 : " << ptr->c0 << std::endl
            << "num: " << ptr->num << std::endl
            << "c1 : " << ptr->c1 << std::endl
            << std::endl;
}

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int main() {
  Data* ptr = new Data;
  init_data(ptr);

  uintptr_t serialized = serialize(ptr);
  Data* des = deserialize(serialized);

  std::cout << "ptr: " << &(*ptr) << std::endl;
  std::cout << "ptr: " << &(*des) << std::endl << std::endl;

  std::cout << MGN "--deserialized data--" NC << std::endl
            << "c0 : " << des->c0 << std::endl
            << "num: " << des->num << std::endl
            << "c1 : " << des->c1 << std::endl
            << std::endl;
  return 0;
}
