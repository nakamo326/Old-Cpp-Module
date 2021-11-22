#include <iostream>

#include "Array.hpp"
#include "Color.hpp"

int main() {
  std::cout << BLU "Default constructor" NC << std::endl;
  Array<int> arr1(10);
  for (size_t i = 0; i < arr1.size(); ++i) {
    arr1[i] = i;
  }
  std::cout << "arr1: " << arr1 << ", size: " << arr1.size() << std::endl;

  std::cout << BLU "copy constructor" NC << std::endl;
  Array<int> arr2(arr1);
  std::cout << "arr2(arr1): " << arr2 << ", size: " << arr2.size() << std::endl;
  std::cout << std::endl;

  for (size_t i = 0; i < arr2.size(); ++i) {
    arr2[i] = i * 2;
  }
  std::cout << "arr2: " << arr2 << ", size: " << arr2.size() << std::endl;
  std::cout << std::endl;
  Array<int> arr3;
  std::cout << "arr3: " << arr3 << ", size: " << arr3.size() << std::endl;
  std::cout << std::endl;

  std::cout << BLU "assignment arr3 = arr2" NC << std::endl;
  arr3 = arr2;
  std::cout << "arr2: " << arr2 << ", size: " << arr3.size() << std::endl;
  std::cout << "arr3: " << arr3 << ", size: " << arr3.size() << std::endl;

  std::cout << std::endl;
  std::cout << BLU "[] operator" NC << std::endl;
  std::cout << "arr1[-1]: ";
  try {
    std::cout << arr1[-1] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "arr1[10]: ";
  try {
    std::cout << arr1[10] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << BLU "const [] operator" NC << std::endl;
  const Array<int> arr4(4);
  std::cout << "arr4: " << arr4 << ", size: " << arr4.size() << std::endl;
  std::cout << "arr4[1]: " << arr4[1] << std::endl;
  std::cout << "arr4[5]: ";
  try {
    std::cout << arr4[5] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}