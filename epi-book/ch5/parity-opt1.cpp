#include<iostream>

int main (void) {
  unsigned int x = 3;
  unsigned int saved_x = x;
  unsigned short parity = 0;

  while (x) {
    parity ^= 1;
    x &= (x-1);
  }
  std::cout << "Parity of " << saved_x << " is " << parity << std::endl;
  return 0;
}
