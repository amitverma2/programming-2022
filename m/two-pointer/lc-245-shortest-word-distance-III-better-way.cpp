class Solution {
    unordered_map<string, vector<int>> indexes;
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int shortest = wordsDict.size();
        int i1 = shortest;
        int i2 = -shortest;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1)
                i1 = i;
            if (wordsDict[i] == word2) {
                if (word1 == word2) {
                    i1 = i2;
                }
                i2 = i;
            }
            shortest = min(shortest, abs(i1 - i2));
        }
        return shortest;
    }
};

