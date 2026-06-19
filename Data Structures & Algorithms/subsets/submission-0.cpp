class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& subset, const vector<int>& nums, int i) {
        if(i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(result, subset, nums, i+1);
        subset.pop_back();
        backtrack(result, subset, nums, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(result, subset, nums, 0);
        return result;
    }
};
