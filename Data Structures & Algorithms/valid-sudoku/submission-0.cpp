class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row checking 
        for(int i=0; i<9; i++) {
            unordered_map<char, int> count;
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') count[board[i][j]]++;
                if(count[board[i][j]] > 1) return false;
            }
        }

        for(int i=0; i<9; i++) {
            unordered_map<char, int> count;
            for(int j=0; j<9; j++) {
                if(board[j][i] != '.') count[board[j][i]]++;
                if(count[board[j][i]] > 1) return false;
            }
        }

        for(int row=0; row<9; row+=3) {
            for(int col=0; col<9; col+=3) {
                unordered_map<char, int> count;
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        if(board[row+i][col+j] != '.') count[board[row+i][col+j]]++;
                        if(count[board[row+i][col+j]] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};
