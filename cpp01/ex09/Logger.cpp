#include "Logger.hpp"

Logger::Logger() {
  // カレントディレクトリlogファイル開く
  // もしすでにlogファイルが存在したら、追記する。
}

Logger::~Logger() {
}

void Logger::logToConsole(std::string const& message) {
  (void)message;
}

void Logger::logToFile(std::string const& message) {
  (void)message;
}

// call from logTo~ ?
std::string Logger::makeLogEntry(std::string const& message) {
  std::time_t res = std::time(NULL);
  std::stringstream ss;
  char buf[40];
  std::strftime(buf, 40, "%Y/%m/%d %X", std::localtime(&res));
  ss << "[" << buf << "] " << message;
  return ss.str();
}

void Logger::log(std::string const& dest, std::string const& message) {
  std::string log = makeLogEntry(message);
  std::cout << log << std::endl;
  (void)dest;
}
