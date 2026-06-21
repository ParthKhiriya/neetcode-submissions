class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        capture(board);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private: 
    void capture(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(board[row][col] == 'O') {
                board[row][col] = 'T';

                for(int i=0; i<4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
};
