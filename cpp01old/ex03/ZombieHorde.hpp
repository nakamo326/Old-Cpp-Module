#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Zombie.hpp"

class ZombieHorde {
  private:
  std::string m_type;
  Zombie* m_horde;
  int m_num;
  std::string get_random_name();

  public:
  ZombieHorde(int N);
  ZombieHorde(int N, std::string type);
  ~ZombieHorde();
  void announce();
};

#endif