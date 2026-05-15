class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> arr;
        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        for(auto it: st) {
            arr.push_back(it);
        }

        int maxCount = 1;
        int count = 1;
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i+1] == arr[i]+1) {
                count++;
            }
            else {
                count = 1;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
