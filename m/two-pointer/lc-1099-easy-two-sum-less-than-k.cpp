class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = -1;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] < k) {
                sum = max(sum, nums[i] + nums[j]);
                i++;
            } else {
                j--;
            }
        }
        return sum;
    }
};

