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

        vector<int> vis(n, 0);
        int totalComponents = 0;
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0)  {
                dfs(adjList, vis, i);
                totalComponents++;
            }
        }
        return totalComponents;
    }

private:
    void dfs(const vector<vector<int>>& adjList, vector<int>& vis, int node) {
        vis[node] = 1;
        for(auto it: adjList[node]) {
            if(!vis[it]) {
                dfs(adjList, vis, it);
            }
        }
    }
};
