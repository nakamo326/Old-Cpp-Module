#include "Karen.hpp"

int main(void) {
  Karen karen;
  karen.complain("DEBUG");
  karen.complain("INFO");
  karen.complain("WARNING");
  karen.complain("ERROR");
  karen.complain("NO_SUCH_OPTION");
  return 0;
}
