#include "sed.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' ||
      argv[3][0] == '\0') {
    std::cout << "USAGE: ./replace [filename] [search] [replace]" << std::endl;
    return 1;
  }
  sed(argv[1], argv[2], argv[3]);
  return 0;
}
