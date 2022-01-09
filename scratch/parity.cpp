#include<iostream>
#include<cmath>

unsigned short parityBruteForce(unsigned long x) {
  unsigned short parity = 0;
  while (x) {
    if (x & 0x1) parity ^= 0x1;
    x >>= 1;
  }
  return parity;
}

unsigned short parityBruteForceOpt1(unsigned long x) {
  unsigned short parity = 0;
  while (x) {
    parity ^= 0x1;
    x &= (x-1);
  }
  return parity;
}

unsigned short parityByLookup(unsigned long x) {
  const unsigned int pTableWidth = 16;
  const unsigned long pTableMask = 0xFFFFUL;
  const unsigned int pTableSize = std::pow(2, pTableWidth);
  unsigned short pTable[pTableSize];
  static bool pTableInited = false;

  if (!pTableInited) {
    for (int i = 0; i < pTableSize; ++i) {
      pTable[i] = parityBruteForce(i);
    }
    pTableInited = true;
  }

  return pTable[x & pTableMask] ^
    pTable[((x >> pTableWidth) & pTableMask)] ^
    pTable[((x >> 2*pTableWidth) & pTableMask)] ^
    pTable[((x >> 3*pTableWidth) & pTableMask)];
}

unsigned short parityAssociative(unsigned long x) {
  x ^= x>>32;
  x ^= x>>16;
  x ^= x>>8;
  x ^= x>>4;
  x ^= x>>2;
  x ^= x>>1;
  return x & 0x1;
}

int main (void) {
  for (int i = 0 ; i < 20; i++) {
    std::cout << i << " : " <<
      parityBruteForce(i) << ", " <<
      parityBruteForceOpt1(i) << ", " <<
      parityByLookup(i) << ", " <<
      parityAssociative(i) << std::endl;
  }
  return 0;
}
