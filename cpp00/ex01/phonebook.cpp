#include "phonebook.hpp"

PhoneBook::PhoneBook() {
  this->index = 0;
}

bool PhoneBook::add() {
  const char q_list[][15] = {
      "first name", "last name", "nickname", "phone number", "darkest secret"};
  std::string answer;

  if (this->index == MAX_LINE) {
    std::cout << "CONTACT IS MAX!" << std::endl;
    return true;
  }
  for (int i = 0; i < 5; i++) {
    std::cout << q_list[i] << ": ";
    std::getline(std::cin, answer, '\n');
    if (std::cin.eof())
      return false;
    this->book[index].set_info(i, answer);
  }
  std::cout << "CONTACT IS ADDED!" << std::endl;
  this->index += 1;
  return true;
}

bool PhoneBook::search() {
  const char q_list[][15] = {
      "first name", "last name", "nickname", "phone number", "darkest secret"};
  std::string str;
  int index;
  bool f;

  // if there is no contact, then return.
  if (this->index == 0) {
    std::cout << "NO CONTACT RECORDED..." << std::endl;
    return true;
  }

  // print contact's list. if field has more than 10 chars, make new string.
  std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
  for (int i = 0; i < this->index; i++) {
    std::cout << std::left << std::setw(10) << i << "|";
    for (int j = 0; j < 3; j++) {
      str = this->book[i].get_info(j);
      if (str.length() > 10)
        str = str.substr(0, 9) + ".";
      std::cout << std::left << std::setw(10) << str << "|";
    }
    std::cout << std::endl;
  }

  // get index number.
  f = false;
  while (f == false) {
    std::cout << "INPUT INDEX: ";
    std::getline(std::cin, str);
    if (std::cin.eof())
      return false;
    if (str.length() != 1 || !(str[0] >= '0' && str[0] <= '7') ||
        std::atoi(str.c_str()) >= this->index) {
      std::cout << "INVALID INPUT!" << std::endl
                << "PLEASE INPUT: 0 ~ " << this->index - 1 << std::endl;
    } else {
      index = std::atoi(str.c_str());
      f = true;
    }
  }

  // print all fields per line.
  for (int i = 0; i < 5; i++) {
    std::cout << std::left << std::setw(14) << q_list[i] << " | ";
    std::cout << std::left << this->book[index].get_info(i) << std::endl;
  }
  return true;
}
