#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  private:
  std::string m_name;
  std::string m_type;

  public:
  Zombie();
  Zombie(std::string name, std::string type);
  ~Zombie();
  void announce(void);
  void set_characteristics(std::string name, std::string type);
};

#endif
