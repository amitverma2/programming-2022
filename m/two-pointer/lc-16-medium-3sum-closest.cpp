class Solution {
public:
    int twoSumClosest(vector<int> &nums, int target, int a, int left) {
        int i = left;
        int j = nums.size() - 1;
        int best = a + nums[i] + nums[j];
        while (i < j) {
            if (abs(target - (a + nums[i] + nums[j])) < abs(target - best)) {
                best = a + nums[i]+nums[j];
            }
            if (target < a + nums[i] + nums[j]) {
                j--;
            } else if (target > a + nums[i] + nums[j]) {
                i++;
            } else {
                return a + nums[i] + nums[j];
            }
        }
        return best;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        bool sum_inited = false;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int best =
                twoSumClosest(nums, target, nums[i],
                              i + 1);
            if (sum_inited) {
                if (abs(target - best) < abs(target - sum)) {
                    sum = best;
                }
            } else {
                sum_inited = true;
                sum = best;
            }
        }
        return sum;
    }
};

