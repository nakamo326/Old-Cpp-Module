#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
class Logger {
  private:
  void logToConsole(std::string log);
  void logToFile(std::string log);
  void makeLogEntry(std::string msg);

  public:
  Logger();
  ~Logger();
  log(std::string const& dest, std::string const& message);
};

Logger::Logger() {
}

Logger::~Logger() {
}

#endif