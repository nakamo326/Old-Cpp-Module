#include "Replace.hpp"

int main(int argc, char const* argv[]) {
  if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' ||
      argv[3][0] == '\0') {
    std::cout << "USAGE: ./replace [filename] [search] [replace]" << std::endl;
    return 1;
  }
  try {
    Replace rep;
    rep.sed(argv[1], argv[2], argv[3]);
  } catch (const char* e) {
    std::cerr << e << std::endl;
    return 1;
  }
  return 0;
}
