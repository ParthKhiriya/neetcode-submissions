class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        int second_last_element = nums[0];
        int last_element = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            int currentElement = max(last_element, nums[i] + second_last_element);
            second_last_element = last_element;
            last_element = currentElement;
        }

        return last_element;
    }
};
