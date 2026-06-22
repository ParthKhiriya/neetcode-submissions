class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<int> q;
        vector<int> vis(n, 0);
        int totalComponents = 0;
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0)  {
                q.push(i);
                totalComponents++;
            }

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto it: adjList[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }

        return totalComponents;
    }
};
