#include<iostream>

int main (void) {
  unsigned int x = 3;

  unsigned short parity = 0;
  unsigned int saved_x = x;
  while(x) {
    parity ^= (x & 0x1);
    x >>= 1;
  }
  std::cout << "Parity of " << saved_x << " is " << parity << std::endl;
  return 0;
}
