#include<iostream>
#include<limits>

int main (void) {
  std::cout << "min char = " << (int)std::numeric_limits<char>::min() << std::endl;
  std::cout << "max char = " << (int)std::numeric_limits<char>::max() << std::endl;
  std::cout << "min short = " << std::numeric_limits<short>::min() << std::endl;
  std::cout << "max short = " << std::numeric_limits<short>::max() << std::endl;
  std::cout << "min int = " << std::numeric_limits<int>::min() << std::endl;
  std::cout << "max int = " << std::numeric_limits<int>::max() << std::endl;
  std::cout << "min long int = " << std::numeric_limits<long int>::min() << std::endl;
  std::cout << "max long int = " << std::numeric_limits<long int>::max() << std::endl;
  std::cout << "min float = " << std::numeric_limits<float>::min() << std::endl;
  std::cout << "max float = " << std::numeric_limits<float>::max() << std::endl;
  std::cout << "min double = " << std::numeric_limits<double>::min() << std::endl;
  std::cout << "max double = " << std::numeric_limits<double>::max() << std::endl;
  return 0;
}
