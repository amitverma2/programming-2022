class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2 && sum != target; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - sum)) {
                    sum = cur;
                }
                if (cur > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return sum;
    }
};

