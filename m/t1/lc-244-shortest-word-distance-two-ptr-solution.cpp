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
        int i = 0; int i_end = w1Indexes.size();
        int j = 0; int j_end = w2Indexes.size();
        int distance = 50000;
        while (i < i_end || j < j_end) {
            int diff = w1Indexes[i] - w2Indexes[j];
            if (diff < 0) diff *= -1;
            if (diff < distance) distance = diff;
            if (w1Indexes[i] < w2Indexes[j]) {
                if (i != i_end - 1) {
                    ++i;
                } else {
                    break; // we are done
                }
            } else {
                if (j != j_end - 1) {
                    ++j;
                } else {
                    break; // we are done
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

