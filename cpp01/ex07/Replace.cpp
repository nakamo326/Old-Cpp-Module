#include "Replace.hpp"

Replace::Replace(const char* argv[])
    : m_filepath(argv[1]), m_search(argv[2]), m_replacement(argv[3]) {
}

Replace::~Replace() {
}

int Replace::sed() {
  if (!read_file())
    return EXIT_FAILURE;
  replace_string();
  if (!output_file())
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}

bool Replace::read_file() {
  std::ifstream ifs(m_filepath);
  std::string line;

  if (!ifs.is_open()) {
    std::cerr << "failed to open the source file." << std::endl;
    return false;
  }
  while (std::getline(ifs, line)) {
    m_file_contents += line;
    m_file_contents.push_back('\n');
  }
  return true;
}

void Replace::replace_string() {
  std::size_t i = 0;
  std::size_t replacement_length = strlen(m_replacement);

  while (true) {
    i = m_file_contents.find(m_search, i);
    if (i == std::string::npos)
      break;
    m_file_contents.erase(i, strlen(m_search));
    m_file_contents.insert(i, m_replacement);
    i += replacement_length;
  }
}

bool Replace::output_file() {
  std::string output_path = std::string(m_filepath) + ".replace";
  std::ofstream ofs(output_path.c_str());
  if (!ofs.is_open()) {
    std::cerr << "failed to open output file." << std::endl;
    return false;
  }
  ofs << m_file_contents;
  return true;
}
