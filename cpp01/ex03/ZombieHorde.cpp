#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
  m_num = N;
  m_type = std::string("none");
  if (N > 0) {
    m_horde = new Zombie[N];
    for (int i = 0; i < N; i++)
      m_horde[i].set_characteristics(get_random_name(), m_type);
  } else
    std::cout << "please input over 1 number." << std::endl;
}

ZombieHorde::ZombieHorde(int N, std::string type) {
  m_num = N;
  m_type = type;
  if (N > 0) {
    m_horde = new Zombie[N];
    for (int i = 0; i < N; i++)
      m_horde[i].set_characteristics(get_random_name(), m_type);
  } else
    std::cout << "please input over 1 number." << std::endl;
}

ZombieHorde::~ZombieHorde() {
  delete[] m_horde;
}

std::string ZombieHorde::get_random_name() {
  const std::string name_list[6] = {
      "Adam", "Bob", "Charles", "Deny", "Elena", "Fabian"};

  int random_val = std::rand() % 6;
  return name_list[random_val];
}

void ZombieHorde::announce() {
  for (int i = 0; i < m_num; i++) {
    m_horde[i].announce();
  }
}