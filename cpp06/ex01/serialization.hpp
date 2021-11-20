#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>

typedef struct s_data {
  int num0;
  int num1;
} Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif  // SERIALIZATION_HPP
