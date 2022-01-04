#include<iostream>
#include<climits>

class Solution {
  public:
    int bitwiseComplement(int n) {
      if (n == 0) return 1;
      int out = 0;
      bool found = false;
      for (int i = sizeof(int)*8 - 1;
           i >= 0; --i) {
        bool set = ((0x1 << i) & n);
        if (found) {
          if (!set) {
            out |= (0x1 << i);
          }
        } else {
          if (set) {
            found = true;
          }
        }
      }
      return out;
    }
};

int main(void) {
  Solution * obj = new Solution;
  int n = INT_MAX; 
  std::cout << "n = " << n << " ; complement = " << obj->bitwiseComplement(n) << std::endl;
  return 0;
}
