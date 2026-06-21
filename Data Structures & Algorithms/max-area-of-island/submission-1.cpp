class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>>& grid, int& area) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
            return;
        }

        grid[row][col] = 0;
        area++;

        for(int i=0; i<4; i++) {
            dfs(row + delRow[i], col + delCol[i], grid, area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      int maxArea = 0;

      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                int area = 0;
                dfs(i, j, grid, area);
                maxArea = max(maxArea, area);
            }
        }
      }
      return maxArea; 
    }
};
