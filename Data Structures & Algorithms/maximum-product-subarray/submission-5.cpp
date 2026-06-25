class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int res = nums[0];
        int curMax = 1;
        int curMin = 1;

        for(int num: nums) {
            int temp = curMax * num;
            curMax = max(num, max(curMax*num, curMin*num));
            curMin = min(num, min(temp, curMin*num));
            res = max(res, curMax);
        }

        return res;
    }
};
