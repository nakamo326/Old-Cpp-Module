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
    throw std::string(path);
  while (std::getline(ifs, line)) {
    contents += line;
    if (!ifs.eof())
      contents.push_back('\n');
  }
  std::string output_path = std::string(path) + ".replace";
  std::ofstream ofs(output_path.c_str());
  if (!ofs)
    throw std::string(path) + ".replace";
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
