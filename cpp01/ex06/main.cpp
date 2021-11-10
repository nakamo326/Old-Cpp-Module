#include "Karen.hpp"

int main(int argc, char const *argv[]) {
  Karen karen;
  int level;
  const std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  if (argc != 2)
    return 1;
  level = -1;
  for (int i = 0; i < 4; i++) {
    if (argv[1] == l[i])
      level = i;
  }
  switch (level) {
    case 0:
      karen.complain("DEBUG");
    case 1:
      karen.complain("INFO");
    case 2:
      karen.complain("WARNING");
    case 3:
      karen.complain("ERROR");
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
  return 0;
}
