#include "phonebook.hpp"

PhoneBook::PhoneBook() {
  m_index = 0;
}

bool PhoneBook::add() {
  std::string answer;

  if (m_index == MAX_LINE) {
    std::cout << "CONTACT IS MAX!" << std::endl;
    return true;
  }
  for (int i = 0; i < Contact::q_num; i++) {
    std::cout << Contact::q_list[i] << ": ";
    std::getline(std::cin, answer, '\n');
    if (std::cin.eof())
      return false;
    m_book[m_index].set_info(i, answer);
  }
  std::cout << "CONTACT IS ADDED!" << std::endl;
  m_index += 1;
  return true;
}

void PhoneBook::display_list() {
  std::string str;

  std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
  for (int i = 0; i < m_index; i++) {
    std::cout << std::left << std::setw(10) << i << "|";
    for (int j = 0; j < 3; j++) {
      str = m_book[i].get_info(j);
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
  int target_i = -1;

  while (true) {
    std::cout << "INPUT INDEX: ";
    std::getline(std::cin, str);
    if (std::cin.eof())
      break;
    if (str.length() != 1 || !(str[0] >= '0' && str[0] <= 48 + (m_index - 1))) {
      std::cout << "INVALID INPUT!" << std::endl
                << "PLEASE INPUT: 0 ~ " << m_index - 1 << std::endl;
    } else {
      target_i = std::atoi(str.c_str());
      break;
    }
  }
  return target_i;
}

bool PhoneBook::search() {
  std::string str;
  int target_i;

  if (m_index == 0) {
    std::cout << "NO CONTACT RECORDED..." << std::endl;
    return true;
  }
  display_list();
  target_i = get_index();
  if (target_i == -1)
    return false;
  for (int i = 0; i < Contact::q_num; i++) {
    std::cout << std::left << std::setw(15) << Contact::q_list[i] << " | ";
    std::cout << std::left << m_book[target_i].get_info(i) << std::endl;
  }
  return true;
}
