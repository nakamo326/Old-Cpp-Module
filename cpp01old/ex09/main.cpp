#include "Logger.hpp"

int main() {
  Logger logger;
  logger.log("File", "first append to logfile");
  logger.log("File", "log of something2");
  logger.log("File", "log of something3");
  logger.log("Console", "log of something4");

  return 0;
}
