class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, {}, nums);
        return res;
    }

    void backtrack(int i, vector<int> cur, vector<int>& nums) {
        res.push_back(cur);

        for(int j=i; j<nums.size(); j++) {
            if(j>i && nums[j] == nums[j-1]) {
                continue;
            }
            cur.push_back(nums[j]);
            backtrack(j+1, cur, nums);
            cur.pop_back();
        }
    }
};
