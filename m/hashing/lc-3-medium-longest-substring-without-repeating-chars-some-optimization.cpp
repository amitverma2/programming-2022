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
                if (prev < start) {
                    // no op, we don't care about this
                    indexes[s[cur]] = cur;
                } else {
                    start = prev + 1;
                    indexes[s[cur]] = cur;
                }
            }
            length = max(length, cur - start + 1);
            cur++;
        }
        return length;
    }
};

