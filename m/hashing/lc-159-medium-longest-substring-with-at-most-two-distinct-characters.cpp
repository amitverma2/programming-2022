class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = 0;
        int start = 0;
        int cur = 0;
        unordered_map<char, int> last;
        while (cur < s.size()) {
            int c = s[cur];
            // other processing here...
            if (last.find(c) != last.end() || last.size() < 2) {
                last[c] = cur;
            } else {
                // it's a new char and last is having 2 chars already
                // find the least last char to remove in the last map
                char x;
                int max = s.size();
                for (auto y: last) {
                    if (y.second < max) {
                        x = y.first;
                        max = y.second;
                    }
                }
                last.erase(x);
                start = max + 1;
                last[c] = cur;
            }
            len = max(len, cur - start + 1);
            cur++;
        }
        return len;
    }
};

