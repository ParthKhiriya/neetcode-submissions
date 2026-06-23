class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adjList[i].push_back({dist, j});
                adjList[j].push_back({dist, i});
            }
        }

        vector<int> vis(adjList.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for(auto& it: adjList[node]) {
                int edgeW = it.first;
                int adjNode = it.second;

                if(vis[adjNode] == 0) {
                    pq.push({edgeW, adjNode});
                }
            }
        }

        return sum;
    }
};
