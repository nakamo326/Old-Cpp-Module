#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

class Logger {
  private:
  void logToConsole(std::string const& message);
  void logToFile(std::string const& message);
  std::string makeLogEntry(std::string const& message);

  public:
  Logger();
  ~Logger();
  void log(std::string const& dest, std::string const& message);
};

#endif