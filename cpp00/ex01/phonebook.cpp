#include "phonebook.hpp"

PhoneBook::PhoneBook() {
  this->index = 0;
}

std::string PhoneBook::get_question(int i) {
  const std::string q_list[11] = {"first name",
                                  "last name",
                                  "nickname",
                                  "login",
                                  "postal address",
                                  "email address",
                                  "phone number",
                                  "birthday date",
                                  "favorite meal",
                                  "underwear color",
                                  "darkest secret"};

  return q_list[i];
}

bool PhoneBook::add() {
  std::string answer;

  if (this->index == MAX_LINE) {
    std::cout << "CONTACT IS MAX!" << std::endl;
    return true;
  }
  for (int i = 0; i < this->q_num; i++) {
    std::cout << get_question(i) << ": ";
    std::getline(std::cin, answer, '\n');
    if (std::cin.eof())
      return false;
    this->book[index].set_info(i, answer);
  }
  std::cout << "CONTACT IS ADDED!" << std::endl;
  this->index += 1;
  return true;
}

void PhoneBook::display_list() {
  std::string str;

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
}

// get index number. return -1 when error is.
int PhoneBook::get_index() {
  std::string str;
  int index = -1;

  while (true) {
    std::cout << "INPUT INDEX: ";
    std::getline(std::cin, str);
    if (std::cin.eof())
      break;
    if (str.length() != 1 ||
        !(str[0] >= '0' && str[0] <= 48 + (this->index - 1))) {
      std::cout << "INVALID INPUT!" << std::endl
                << "PLEASE INPUT: 0 ~ " << this->index - 1 << std::endl;
    } else {
      index = std::atoi(str.c_str());
      break;
    }
  }
  return index;
}

bool PhoneBook::search() {
  std::string str;
  int index;

  if (this->index == 0) {
    std::cout << "NO CONTACT RECORDED..." << std::endl;
    return true;
  }
  display_list();
  index = get_index();
  if (index == -1)
    return false;
  for (int i = 0; i < this->q_num; i++) {
    std::cout << std::left << std::setw(15) << get_question(i) << " | ";
    std::cout << std::left << this->book[index].get_info(i) << std::endl;
  }
  return true;
}
