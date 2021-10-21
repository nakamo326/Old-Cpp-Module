#include "Human.hpp"

Human::Human() {
}

Human::~Human() {
}

void Human::meleeAttack(std::string const& target) {
  std::cout << "Human attacked " << target << " with the sword." << std::endl;
}

void Human::rangedAttack(std::string const& target) {
  std::cout << "Human attacked " << target << " with the gun." << std::endl;
}

void Human::intimidatingShout(std::string const& target) {
  std::cout << "Human shouted to " << target << " intimidatingly." << std::endl;
}

void Human::action(std::string const& action_name, std::string const& target) {
  void (Human::*fp[3])(std::string const& target) = {
      &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

  const std::string actions[4] = {"melee", "ranged", "shout"};

  for (size_t i = 0; i < 4; i++) {
    if (action_name == actions[i])
      (this->*fp[i])(target);
  }
}
