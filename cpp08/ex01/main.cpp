// int max int min
// span max size check

#include <iostream>
#include <numeric>

#include "Span.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"

int main() {
  Span sp = Span(5);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << BLU "== test of assignation and deep copy ===" NC << std::endl;
  try {
    Span* copy = new Span(3);
    copy->addNumber(5);
    copy->addNumber(3);
    copy->addNumber(17);
    Span assignation;
    assignation = *copy;
    delete copy;
    std::cout << assignation << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;
  std::cout << BLU "== span size exception check ===" NC << std::endl;
  try {
    sp.addNumber(42);
  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << NC << '\n';
  }
  std::cout << std::endl;
  {
    std::cout << BLU "== minus test ===" NC << std::endl;
    Span mc = Span(2);
    mc.addNumber(20);
    mc.addNumber(-20);
    std::cout << mc << std::endl;
    std::cout << mc.shortestSpan() << std::endl;
    std::cout << mc.longestSpan() << std::endl;
  }
  {
    std::cout << BLU "== int_max int_min ===" NC << std::endl;
    Span mc = Span(2);
    mc.addNumber(std::numeric_limits<int>::max());
    mc.addNumber(std::numeric_limits<int>::min());
    std::cout << mc << std::endl;
    std::cout << mc.shortestSpan() << std::endl;
    std::cout << mc.longestSpan() << std::endl;
  }

  return 0;
}
