class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1;
             i < j;) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return vector<int>({ i + 1, j + 1});
            }
            if (sum > target)
                j--; // move in a direction where sum is going to decrease
            if (sum < target)
                i++; // move in a direction where sum is going to increase
        }
        return vector<int>();
    }
};

