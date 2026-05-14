class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        bool duplicate = false;
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]] > 1) {
                duplicate = true;
                break;
            }
        }

        return duplicate;
    }
};