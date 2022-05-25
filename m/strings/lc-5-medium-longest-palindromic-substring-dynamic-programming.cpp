class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        int maxL = 0;
        int maxR = 0;
        bool P[1000][1000] = { false };
        for (int sz = 1; sz <= s.length(); ++sz) {
            for (int i = 0; i <= s.length() - sz; ++i) {
                if (sz == 1) {
                    P[i][i] = true;
                } else if (sz == 2) {
                    if (P[i][i+1] = (s[i] == s[i+1])) {
                        if (max < 2) {
                            max = 2;
                            maxL = i;
                            maxR = i+1;
                        }
                    }
                } else {
                    int l = i;
                    int r = i + sz - 1;
                    if (P[l][r] = (P[l + 1][r - 1]?(s[l] == s[r]):false)) {
                        if (r - l + 1 > max) {
                            max = r - l + 1;
                            maxL = l;
                            maxR = r;
                        }
                    }
                }
            }
        }
        return s.substr(maxL, maxR - maxL + 1);
    }
};

