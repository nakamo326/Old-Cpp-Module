#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>

#include "Zombie.hpp"

class ZombieEvent {
  private:
  std::string m_type;

  public:
  ZombieEvent();
  ~ZombieEvent();
  void setZombieType(std::string type);
  Zombie* newZombie(std::string name);
  void randomChump();
};

#endif
