class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        pq.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while(!pq.empty()) {
            auto curr = pq.top();
            int timeSoFar = curr[0];
            int row = curr[1];
            int col = curr[2];
            pq.pop();
            if(row == n-1 && col == n-1) return timeSoFar;

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(newRow < 0 || newRow == n || newCol < 0 || newCol == n || visit.count({newRow, newCol})) {
                    continue;
                }
                visit.insert({newRow, newCol});
                int newTime = max(timeSoFar, grid[newRow][newCol]);
                pq.push({newTime, newRow, newCol});
            }
        }

        return n * n;
    }
};
