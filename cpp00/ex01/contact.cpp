#include "contact.hpp"

void Contact::set_info(int index, std::string str) {
  this->info[index] = str;
}

std::string Contact::get_info(int index) {
  return this->info[index];
}
