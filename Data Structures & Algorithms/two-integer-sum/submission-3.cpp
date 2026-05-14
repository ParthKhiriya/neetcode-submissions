class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<pair<int, int>> store;
        for(int i=0; i<n; i++) {
            store.push_back({arr[i], i});
        }

        sort(store.begin(), store.end());
        
        int left = 0;
        int right = n-1;

        while(left < right) {
            int value = store[left].first + store[right].first;
            
            if(value == target) return {min(store[left].second, store[right].second), max(store[left].second, store[right].second)};
            else if(value > target) right--;
            else left++;
        }

        return {};
    }
};
