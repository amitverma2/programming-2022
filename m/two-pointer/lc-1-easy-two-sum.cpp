class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0 ; i < nums.size(); ++i) {
            auto x = hash.find(target - nums[i]);
            if (x != hash.end()) {
                return vector<int>({ x->second, i });
            }
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};

