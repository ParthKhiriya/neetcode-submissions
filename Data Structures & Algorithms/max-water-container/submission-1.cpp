class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        int left = 0;
        int right = n-1;

        while(left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            maxArea = max(area, maxArea);

            if(heights[left] <= heights[right]) left++;
            else right--;
        }

        return maxArea;
    }
};
