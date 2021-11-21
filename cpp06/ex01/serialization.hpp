#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include "Color.hpp"

typedef struct s_data {
  char c0[8];
  int num;
  char c1[8];
} Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif  // SERIALIZATION_HPP
