/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> knowsPpl(n, 0);
        vector<int> knownByPpl(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (knows(i, j)) {
                    knowsPpl[i]++;
                    knownByPpl[j]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (knowsPpl[i] == 0 &&
                knownByPpl[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

