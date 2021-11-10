#include "Replace.hpp"

Replace::Replace() {
}

Replace::~Replace() {
}

void Replace::sed(const char* path, std::string search,
                  std::string replacement) {
  std::string contents = readFile(path);
  std::string output_path = std::string(path) + ".replace";
  std::ofstream ofs(output_path.c_str());
  if (!ofs)
    throw std::string(path) + ".replace";
  ofs << replace(contents, search, replacement);
  return;
}

std::string Replace::readFile(const char* path) {
  std::ostringstream oss;
  std::ifstream ifs(path);
  if (!ifs)
    throw std::string(path);
  oss << ifs.rdbuf();
  return oss.str();
}

std::string Replace::replace(std::string contents, std::string search,
                             std::string replacement) {
  std::size_t i = 0;
  while (1) {
    i = contents.find(search, i);
    if (i == std::string::npos)
      break;
    contents.erase(i, search.size());
    contents.insert(i, replacement);
    i += replacement.size();
  }
  return contents;
}
