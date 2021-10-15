#include <iostream>
#include <string>

#include "contact.hpp"
#include "phonebook.hpp"

int main(void) {
  std::string cmd;
  PhoneBook pb;

  while (true) {
    std::cout << "INPUT COMMAND: ";
    std::getline(std::cin, cmd);
    if (std::cin.eof())
      break;
    if (cmd == "ADD") {
      if (!pb.add())
        break;
    } else if (cmd == "SEARCH") {
      if (!pb.search())
        break;
    } else if (cmd == "EXIT") {
      std::cout << "BYE~" << std::endl;
      break;
    } else {
      std::cout << "INVALID COMMAND!" << std::endl;
      std::cout << "USAGE: ADD, SEARCH, EXIT" << std::endl;
      continue;
    }
  }
  if (std::cin.eof())
    std::cout << std::endl << "GOT EOF. BYE~" << std::endl;
  return 0;
}
