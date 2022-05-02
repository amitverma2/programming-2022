class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<unsigned int, int> frequency;
        unordered_map<unsigned int, string> sequence;
        vector<string> results;
        unordered_map<char, unsigned short> n_map = {{'A', 0},
                                                     {'C', 1},
                                                     {'G', 2},
                                                     {'T', 3}};
        
        unsigned int mask = 0xFFFFF;
        unsigned int val = 0;
        for (int i = 0; i < s.size(); ++i) {
            val <<= 2;
            val |= n_map[s[i]];
            val &= mask;
            if (i >= 9) {
                frequency[val]++;
                if (frequency[val] == 2) {
                    results.push_back(s.substr(i - 9, 10));
                }
            }
        }
        
        return results;
    }
};

