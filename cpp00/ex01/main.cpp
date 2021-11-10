#include <iostream>
#include <string>

#include "Contact.hpp"
#include "Phonebook.hpp"

int main(void) {
  PhoneBook pb;

  try {
    pb.entry();
  } catch (const std::exception& e) {
    std::cerr << "\nMAYBE INPUT/OUTPUT ISSUE. BYE" << std::endl;
  }
  return 0;
}
