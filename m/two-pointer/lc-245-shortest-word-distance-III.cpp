class Solution {
    unordered_map<string, vector<int>> indexes;
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        for (int i = 0; i < wordsDict.size(); ++i)
            indexes[wordsDict[i]].push_back(i);
        
        vector<int> &indexes1 = indexes[word1];
        vector<int> &indexes2 = indexes[word2];
        int shortest = 200000;
        if (word1 == word2) {
           for (int i = 0; i < indexes1.size() - 1; ++i) {
               shortest = min(shortest, abs(indexes1[i] - indexes1[i+1]));
           }
        } else {
            int i1 = 0;
            int i2 = 0;
            while (i1 < indexes1.size() && i2 < indexes2.size()) {
                shortest = min(shortest, abs(indexes1[i1] - indexes2[i2]));
                if (indexes1[i1] < indexes2[i2])
                    i1++;
                else
                    i2++;
            }
        }
        return shortest;
    }
};

