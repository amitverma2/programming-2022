class Solution {
public:
    int count2sum(vector<int> &nums, int l, int a, int target) {
        int count = 0;
        int i = l;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = a + nums[i] + nums[j];
            if (sum < target) {
                count += j - i;
                i++;
            } else
                j--;
        }
        return count;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int counts = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            counts += count2sum(nums, i + 1, nums[i], target);
        }
        return counts;
    }
};

