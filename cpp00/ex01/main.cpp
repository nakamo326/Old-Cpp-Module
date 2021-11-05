#include <iostream>
#include <string>

#include "contact.hpp"
#include "phonebook.hpp"

int main(void) {
  PhoneBook pb;

  try {
    pb.entry();
  } catch (const std::exception& e) {
    std::cerr << "\nMAYBE INPUT/OUTPUT ISSUE. BYE" << std::endl;
  }
  return 0;
}
