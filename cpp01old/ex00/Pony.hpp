#include <iostream>

class Pony {
  private:
  std::string m_name;

  public:
  Pony(std::string name);
  ~Pony();
  void cry();
  void run();
};
