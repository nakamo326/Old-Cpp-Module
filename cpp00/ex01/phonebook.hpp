#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "contact.hpp"

#define MAX_LINE 8

class PhoneBook {
 private:
  Contact book[MAX_LINE];
  int index;

 public:
  PhoneBook();
  bool add();
  bool search();
};

#endif