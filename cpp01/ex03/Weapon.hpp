#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
  private:
  std::string m_type;

  public:
  Weapon(std::string type);
  const std::string& getType();
  void setType(std::string type);
};

#endif
