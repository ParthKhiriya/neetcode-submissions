class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A valid tree is nothing but an Undirected Graph with NO CYCLES
        // We will use BFS to solve this problem
        vector<vector<int>> adjList(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        q.push({0, -1});
        vis[0] = 1;
        int visitedNodes = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            visitedNodes++;

            for(auto it: adjList[node]) {
                if(vis[it] == 1) {
                    if(parent != it) {
                        return false;
                    } else {
                        continue;
                    }
                } else {
                    q.push({it, node});
                    vis[it] = 1;
                }
            }
        }

        return visitedNodes == n;
    }
};
