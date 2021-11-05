#include "phonebook.hpp"

PhoneBook::PhoneBook() {
  m_index = 0;
  std::cout.exceptions(std::ostream::badbit | std::ostream::eofbit);
  std::cin.exceptions(std::istream::badbit | std::istream::eofbit);
}

void PhoneBook::entry() {
  std::string cmd;

  while (true) {
    std::cout << "INPUT COMMAND: ";
    std::getline(std::cin, cmd);
    if (cmd == "ADD") {
      add();
    } else if (cmd == "SEARCH") {
      search();
    } else if (cmd == "EXIT") {
      std::cout << "BYE~" << std::endl;
      break;
    } else if (std::cin.good()) {
      std::cout << "INVALID COMMAND!" << std::endl;
      std::cout << "USAGE: ADD, SEARCH, EXIT" << std::endl;
    }
  }
}

void PhoneBook::add() {
  std::string answer;

  if (m_index == MAX_LINE) {
    std::cout << "CONTACT IS MAX!" << std::endl;
    return;
  }
  for (int i = 0; i < Contact::q_num; i++) {
    std::cout << Contact::q_list[i] << ": ";
    std::getline(std::cin, answer, '\n');
    m_book[m_index].set_info(i, answer);
  }
  std::cout << "CONTACT IS ADDED!" << std::endl;
  m_index += 1;
}

void PhoneBook::search() {
  std::string str;

  if (m_index == 0) {
    std::cout << "NO CONTACT RECORDED..." << std::endl;
    return;
  }
  display_list();
  display_contact();
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

void PhoneBook::display_contact() {
  std::string str;
  int target_i = -1;

  while (true) {
    std::cout << "INPUT INDEX: ";
    std::getline(std::cin, str);
    if (str.length() != 1 ||
        !(str[0] >= '0' && str[0] <= '0' + (m_index - 1))) {
      std::cout << "INVALID INPUT!" << std::endl
                << "PLEASE INPUT: 0 ~ " << m_index - 1 << std::endl;
    } else {
      target_i = std::atoi(str.c_str());
      break;
    }
  }
  for (int i = 0; i < Contact::q_num; i++) {
    std::cout << std::left << std::setw(15) << Contact::q_list[i] << " | ";
    std::cout << std::left << m_book[target_i].get_info(i) << std::endl;
  }
}
