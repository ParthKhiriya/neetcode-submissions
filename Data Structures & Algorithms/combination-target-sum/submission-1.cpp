class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int i, vector<int> cur, int total, vector<int>& nums, int target) {
        if(total == target) {
            res.push_back(cur);
            return;
        }

        for(int j=i; j<nums.size(); j++) {
            if (total + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
            backtrack(j, cur, total+nums[j], nums, target);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(0, cur, 0, nums, target);
        return res;
    }
};
