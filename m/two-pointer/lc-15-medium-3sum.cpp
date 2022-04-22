class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) return results;
        sort(nums.begin(), nums.end());
        bool first = false;
        int a;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0) {
                if (nums[i] == a)
                    continue;
            }
            if (nums[i] > 0)
                break;
            a = nums[i];
            for (int j = i + 1, k = nums.size() - 1;
                 j < k;) {
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                if (sum == 0) {
                    results.push_back(vector<int>({a, b, c}));
                    while (j < nums.size() && nums[j] == b) j++;
                    while (j < k && nums[k] == c) k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return results;
    }
};

