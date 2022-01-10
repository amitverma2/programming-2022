#include<iostream>
#include<random>
#include<climits>

unsigned long reverse(unsigned long x) {
  unsigned long y = 0;
  for (int i = 0 ; i < 8*sizeof(unsigned long); ++i) {
    y <<= 1;
    y |= (x & 0x1);
    x >>= 1;
  }
  return y;
}

unsigned long reverseOpt1(unsigned long x) {
  for (int i = 0, j = (8*sizeof(unsigned long)-1); i < j; ++i, --j) {
    if ( ((x>>i)&0x1) != ((x>>j)&0x1)) {
      x ^= ((0x1UL << i) | (0x1UL << j));
    }
  }
  return x;
}

unsigned long reverseOpt2(unsigned long x) {
  const int sz = 16;
  static bool tableInitDone = false;
  static unsigned long reverseLookup[1 << sz];

  if (!tableInitDone) {
    tableInitDone = true;
    for (int i = 0 ; i < (1<<sz); ++i) {
      reverseLookup[i] = reverse(i) >> 3*sz;
      //std::cout << "i = " << i << " reverse i = " << reverseLookup[i] << std::endl;
    }
  }

  const unsigned int mask = 0xFFFF;
  return (reverseLookup[x & mask] << 3*sz) |
    (reverseLookup[(x >> sz) & mask] << 2*sz) |
    (reverseLookup[(x >> 2*sz) & mask] << sz) |
    (reverseLookup[(x >> 3*sz) & mask]);
}

int main (void) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<unsigned long> dis(0, std::numeric_limits<unsigned long>::max());
  for (int i = 0 ; i < 16; ++i) {
    unsigned long x = dis(gen);

    std::cout << std::hex << "x = " << x << " : Rev = " <<
      reverse(x) << ", " <<
      reverseOpt1(x) << ", " <<
      reverseOpt2(x) << " : " <<
      (((reverse(x) == reverseOpt1(x)) && (reverse(x) == reverseOpt2(x)))?"Ok":"Not ok") << std::endl;
  }
  return 0;
}
