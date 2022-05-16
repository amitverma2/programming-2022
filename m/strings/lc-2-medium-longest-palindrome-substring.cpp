class Solution {
public:
    bool isPalindrome (string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string longest = s.substr(0, 1);
        if (s.size() == 1) return longest;
        
        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (longest.size() < j - i + 1 &&
                    isPalindrome(s, i, j)) {
                    longest = s.substr(i, j - i + 1);
                }
            }
        }
        return longest;
    }
};

