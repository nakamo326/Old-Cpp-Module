#include "Cat.hpp"

// no such file
// permission?
//　いっこエラー出ても他のファイル書き出す

int main(int argc, char const* argv[]) {
  Cat cat;
  int ret = EXIT_SUCCESS;

  if (argc == 1)
    ret = cat.readStdIn();
  else {
    for (size_t i = 1; i <= argc; i++) {
      if (cat.readFile(argv[i]) == 1)
        ret = EXIT_FAILURE;
    }
  }
  return ret;
}
