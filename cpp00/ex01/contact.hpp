#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  private:
  std::string info[11];

  public:
  void set_info(int index, std::string str);
  std::string get_info(int index);
};

#endif