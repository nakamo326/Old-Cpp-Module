#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : m_name(name) {
  std::cout << "FR4G-TP " << m_name << ": Hey everybody! Check out my package!"
            << std::endl;
  m_level = 1;
  m_hp = 100;
  m_max_hp = 100;
  m_energy = 100;
  m_max_energy = 100;
  m_melee_attack = 30;
  m_ranged_attack = 20;
  m_armor_reduction = 5;
  std::srand(std::time(NULL));
}

FragTrap::~FragTrap() {
  std::cout << "FR4G-TP " << m_name << ": Poop." << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) {
  std::cout << "FR4G-TP " << m_name << ": Let's get this party started!"
            << std::endl;
  *this = rhs;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this == &rhs) {
    return *this;
  }
  m_name = rhs.m_name;
  m_level = rhs.m_level;
  m_hp = rhs.m_hp;
  m_max_hp = rhs.m_max_hp;
  m_energy = rhs.m_energy;
  m_max_energy = rhs.m_max_energy;
  m_melee_attack = rhs.m_melee_attack;
  m_ranged_attack = rhs.m_ranged_attack;
  m_armor_reduction = rhs.m_armor_reduction;
  return *this;
}

void FragTrap::rangedAttack(std::string const &target) {
  std::cout << "[FR4G-TP " << m_name << " attacks " << target
            << " at range, causing " << m_ranged_attack << "points of damage!]"
            << std::endl;
}

void FragTrap::meleeAttack(std::string const &target) {
  std::cout << "[FR4G-TP " << m_name << " attacks " << target
            << " at melee, causing " << m_melee_attack << "points of damage!]"
            << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  std::cout << "[FR4G-TP " << m_name << " takes " << amount - m_armor_reduction
            << "points of damage!]" << std::endl;
  std::cout << "FR4G-TP " << m_name << ": Ow hohoho, that hurts! Yipes!"
            << std::endl;
  m_hp -= amount - m_armor_reduction;
  if (m_hp < 0)
    m_hp = 0;
}

void FragTrap::beRepaired(unsigned int amount) {
  int gain_hp;
  if ((int)(amount + m_hp) > m_max_hp)
    gain_hp = m_max_hp - m_hp;
  else
    gain_hp = amount;
  m_hp += gain_hp;
  std::cout << "[FR4G-TP " << m_name << " is recovered " << gain_hp
            << "life points!]" << std::endl;
  std::cout << "FR4G-TP " << m_name << ": Sweet life juice!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target) {
  std::string arr[5] = {"This time it'll be awesome, I promise!",
                        "Running the sequencer!",
                        "Place your bets!",
                        "Defragmenting!",
                        "Recompiling my combat code!"};

  if (m_energy <= 25) {
    std::cout << "No Energy!" << std::endl;
    return;
  }
  m_energy -= 25;
  int random_val = std::rand() % 5;
  std::cout << "[FR4G-TP " << m_name << " attacks " << target
            << " with VaultHunter.EXE!!]" << std::endl;
  std::cout << "FR4G-TP " << m_name << ": " << arr[random_val] << std::endl;
}
