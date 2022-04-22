class Solution {
public:
    int maxArea(vector<int>& height) {
        int area_max = 0;
        for (int i = 0, j = height.size() - 1;
             i < j;) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > area_max) area_max = area;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area_max;
    }
};

