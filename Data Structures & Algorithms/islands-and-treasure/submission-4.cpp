class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    q.push({0, {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == INT_MAX && vis[newRow][newCol] == false) {
                    q.push({dist+1, {newRow, newCol}});
                    grid[newRow][newCol] = dist + 1;
                    vis[newRow][newCol] = true;
                }
            }
        }
    }
};
