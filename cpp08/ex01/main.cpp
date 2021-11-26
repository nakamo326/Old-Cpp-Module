// int max int min
// span max size check

#include <iostream>
#include <limits>

#include "Span.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"

int main() {
  Span sp = Span(6);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
  std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
  std::cout << std::endl;
  std::cout << BLU "== test deep copy and modify copy ===" NC << std::endl;
  Span copy(sp);
  copy.addNumber(42);
  std::cout << "sp: " << sp << std::endl;
  std::cout << "copy: " << copy << std::endl;
  std::cout << std::endl;
  std::cout << BLU "== test of assignation and deep copy ===" NC << std::endl;
  try {
    Span* heap = new Span(3);
    heap->addNumber(5);
    heap->addNumber(3);
    heap->addNumber(17);
    Span assignation;
    assignation = *heap;
    delete heap;
    std::cout << assignation << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;
  {
    std::cout << BLU "== span size exception check ===" NC << std::endl;
    try {
      sp.addNumber(42);
      sp.addNumber(42);
    } catch (const std::exception& e) {
      std::cerr << RED << e.what() << NC << '\n';
    }
  }
  std::cout << std::endl;
  {
    std::cout << BLU "== minus test ===" NC << std::endl;
    Span mc = Span(2);
    mc.addNumber(20);
    mc.addNumber(-20);
    std::cout << mc << std::endl;
    std::cout << "ShortestSpan: " << mc.shortestSpan() << std::endl;
    std::cout << "LongestSpan: " << mc.longestSpan() << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << BLU "== int_max int_min ===" NC << std::endl;
    Span mc = Span(2);
    mc.addNumber(std::numeric_limits<int>::max());
    mc.addNumber(std::numeric_limits<int>::min());
    std::cout << mc << std::endl;
    std::cout << "ShortestSpan: " << mc.shortestSpan() << std::endl;
    std::cout << "LongestSpan: " << mc.longestSpan() << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << BLU "== 100000 elm (0 to 999999)===" NC << std::endl;
    Span mc = Span(100000);
    for (size_t i = 0; i < 100000; i++) {
      mc.addNumber(i);
    }
    // std::cout << mc << std::endl;
    std::cout << "ShortestSpan: " << mc.shortestSpan() << std::endl;
    std::cout << "LongestSpan: " << mc.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
