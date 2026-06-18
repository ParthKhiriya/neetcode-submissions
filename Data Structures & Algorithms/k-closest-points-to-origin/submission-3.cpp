class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<vector<int>> maxHeap;

        for(auto it: points) {
            int x = it[0];
            int y = it[1];

            int distance = pow(x, 2) + pow(y, 2);
            maxHeap.push({distance, x, y});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while(maxHeap.size()) {
            vector<int> point;
            point.push_back(maxHeap.top()[1]);
            point.push_back(maxHeap.top()[2]);
            ans.push_back(point);
            maxHeap.pop();
        }

        return ans;
    }
};
