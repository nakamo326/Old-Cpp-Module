#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  public:
  static const int q_num = 11;
  static const std::string q_list[q_num];
  void set_info(int index, std::string &str);
  const std::string &get_info(int index);

  private:
  std::string info[q_num];
};

#endif