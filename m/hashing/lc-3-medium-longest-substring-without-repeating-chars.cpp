class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int start = 0;
        int cur = start;
        unordered_map<char, int> indexes;
        while (cur < s.length()) {
            if (indexes.find(s[cur]) == indexes.end()) {
                indexes[s[cur]] = cur;
            } else {
                int prev = indexes[s[cur]];
                while (start <= prev) {
                    indexes.erase(s[start]);
                    ++start;
                }
                indexes[s[cur]] = cur;
            }
            length = max(length, cur - start + 1);
            cur++;
        }
        return length;
    }
};

