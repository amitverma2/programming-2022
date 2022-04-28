class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        if (nums.size() < 4) return results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum > target) {
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        results.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while (k < l &&
                               nums[k] == nums[k - 1])
                            ++k;
                        --l;
                        while (l > k &&
                               nums[l] == nums[l + 1])
                            --l;
                    }
                }
            }
        }
        return results;
    }
};

