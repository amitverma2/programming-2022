class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0;
        while (l + 1 < arr.size() && arr[l + 1] >= arr[l])
            ++l;
        if (l == arr.size() - 1) return 0; // continuously increasing array

        int r = arr.size() - 1;
        while (r > 0 && arr[r] >= arr[r - 1])
            --r;
        int result = min(r, (int)arr.size() - 1 - l);
        
        // check if something better can be found in between
        int i = 0;
        int j = r;
        while (i <= l && j < arr.size()) {
            if (arr[j] >= arr[i]) {
                result = min(result, j - i - 1);
                ++i;
            } else {
                ++j;
            }
        }
        
        return result;
    }
};

