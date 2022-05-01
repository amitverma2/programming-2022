class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        for (auto s: strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            smap[ss].push_back(s);
        }
        vector<vector<string>> results;
        for (auto s: smap) {
            results.push_back(s.second);
        }
        return results;
    }
};

