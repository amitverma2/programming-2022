class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = -1;
        for (int i = 0; i < nums.size() - 1 && nums[i] < k; ++i) {
            auto j = lower_bound(nums.begin() + i + 1,
                                nums.end(), k - nums[i]) -
                nums.begin() - 1;
            if (j > i) {
                sum = max(sum, nums[i] + nums[j]);
            }
        }
        return sum;
    }
};

