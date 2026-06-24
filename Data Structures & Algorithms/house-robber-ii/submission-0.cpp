class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(house(nums, 0, n-2), house(nums, 1, n-1));
    }

    int house(vector<int>& nums, int start, int end) {
        int second_last_element = 0;
        int last_element = 0;

        for(int i=start; i<=end; i++) {
            int curr = max(last_element, nums[i] + second_last_element);
            second_last_element = last_element;
            last_element = curr;
        }

        return last_element;
    }
};
