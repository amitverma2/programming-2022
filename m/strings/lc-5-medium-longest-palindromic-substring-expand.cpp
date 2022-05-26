class Solution {
public:
    int expand (string &s, int l, int r) {
        while (l >= 0 && r < s.length() &&
               s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        int r = 0;
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i + 1);
            if (l1 > l2) { 
                if (l1 > r - l + 1) {
                    r = i + l1/2;
                    l = i - l1/2;
                }
            } else {
                if (l2 > r - l + 1) {
                    r = i + l2/2;
                    l = i - (l2 - 1)/2;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};

