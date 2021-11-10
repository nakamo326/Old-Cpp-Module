#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

#define MAX_LINE 8

class PhoneBook {
  private:
  Contact m_book[MAX_LINE];
  int m_index;
  void add();
  void search();
  bool is_empty_contact(Contact c);
  void display_list();
  void display_contact();

  public:
  PhoneBook();
  void entry();
};

#endif