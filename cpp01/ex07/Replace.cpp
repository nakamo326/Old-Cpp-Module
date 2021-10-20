#include "Replace.hpp"

Replace::Replace() {
}

Replace::~Replace() {
}

void Replace::sed(const char *path, std::string search,
                  std::string replacement) {
  std::string contents;
  std::string line;
  std::ifstream ifs(path);
  if (!ifs)
    throw "failed to open the source file.";
  while (std::getline(ifs, line)) {
    contents += line;
    contents.push_back('\n');
  }
  std::string output_path = std::string(path) + ".replace";
  std::ofstream ofs(output_path.c_str());
  if (!ofs)
    throw "failed to open output file.";
  ofs << replace(contents, search, replacement);
  return;
}

std::string Replace::replace(std::string contents, std::string search,
                             std::string replacement) {
  std::size_t i = 0;

  while (true) {
    i = contents.find(search, i);
    if (i == std::string::npos)
      break;
    contents.replace(i, search.size(), replacement);
    i += replacement.size();
  }
  return contents;
}
