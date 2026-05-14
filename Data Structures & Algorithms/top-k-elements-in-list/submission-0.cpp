class Solution {
public:

    // bool cmp(pair<int, int>& a, pair<int, int>& b) {
    //     return a.second > b.second;
    // }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        // Counting the frequency of elements using map
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        // Using array for sorting the map
        vector<pair<int, int>> store;
        for(auto& it: mpp) {
            store.push_back(it);
        }
        sort(store.begin(), store.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        // Now print the first k elements
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(store[i].first);
        }

        return ans;
    }
};
