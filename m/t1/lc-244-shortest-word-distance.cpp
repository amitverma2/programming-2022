class WordDistance {
    unordered_map<string, vector<int>> stringIndex;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            stringIndex[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> &w1Indexes = stringIndex[word1];
        vector<int> &w2Indexes = stringIndex[word2];
        int  distance = 50000; // has to be less than this
        for (auto x: w1Indexes) {
            auto i = upper_bound(w2Indexes.begin(), w2Indexes.end(), x);
            if (i != w2Indexes.end()) {
                if (*i - x < distance) {
                    distance = *i - x;
                }
            }
            int * w2_data = w2Indexes.data();
            int w2_size = w2Indexes.size();
            int pos = upper_bound(w2_data, w2_data + w2_size, x) - w2_data;
            if (pos != w2_size) {
                // found upper bound
                --pos;
            } else {
                pos = w2_size - 1;
            }
            if (pos >= 0) {
                if (x - w2_data[pos] < distance) {
                    distance = x - w2_data[pos];
                }
            }
        }
        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */

