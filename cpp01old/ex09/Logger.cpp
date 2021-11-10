#include "Logger.hpp"

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::logToConsole(std::string const& message) {
  std::string log = makeLogEntry(message);
  std::cout << log << std::endl;
}

void Logger::logToFile(std::string const& message) {
  std::string log = makeLogEntry(message);
  if (!m_logFile.is_open()) {
    m_logFile.open(LOGFILE_NAME, std::ios::app);
    if (!m_logFile)
      throw "failed to open output file.";
  }
  m_logFile << log << std::endl;
}

std::string Logger::makeLogEntry(std::string const& message) {
  std::time_t res = std::time(NULL);
  std::stringstream ss;
  char buf[40];
  std::strftime(buf, 40, "%Y/%m/%d %X", std::localtime(&res));
  ss << "[" << buf << "] " << message;
  return ss.str();
}

void Logger::log(std::string const& dest, std::string const& message) {
  void (Logger::*fp[2])(std::string const& message) = {&Logger::logToConsole,
                                                       &Logger::logToFile};
  const std::string dests[2] = {"Console", "File"};

  for (size_t i = 0; i < 2; i++) {
    if (dests[i] == dest)
      (this->*fp[i])(message);
  }
}