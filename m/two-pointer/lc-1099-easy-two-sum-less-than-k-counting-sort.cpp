class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        array<int, 1001> freq;
        freq.fill(0);
        for (auto x : nums) {
            freq[x]++;
        }
        int sum = -1;
        for (int i = 1, j = 1000;
             i <= j;) {
            if (freq[i] == 0) {
                i++;
                continue;
            }
            if (freq[j] == 0) {
                j--;
                continue;
            }
            if (i + j >= k) {
                j--;
            } else {
                if (i != j || freq[i] > 1) {
                    sum = max(sum, i + j);
                }
                i++;
            }
        }
        return sum;
  }
};

