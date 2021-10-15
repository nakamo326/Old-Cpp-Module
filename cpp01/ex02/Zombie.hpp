#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  private:
  std::string m_name;
  std::string m_type;

  public:
  Zombie(std::string name, std::string type);
  ~Zombie();
  void announce(void);
};

#endif
