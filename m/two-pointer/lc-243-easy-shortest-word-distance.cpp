class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int shortest = wordsDict.size();
        int i1 = shortest;
        int i2 = -shortest;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1)
                i1 = i;
            if (wordsDict[i] == word2)
                i2 = i;
            shortest = min(shortest, abs(i1 - i2));
        }
        return shortest;
    }
};

