#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen {
  private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

  typedef void (Karen::*level)();
  static const level LEVELS[];

  public:
  Karen();
  ~Karen();
  void complain(std::string level);
};

#endif