class Solution {
public:
    void backtrack(int open, int closed, int n, vector<string>& res, string& st) {
        if(open == closed && open == n) {
            res.push_back(st);
            return;
        }

        if(open < n) {
            st += '(';
            backtrack(open+1, closed, n, res, st);
            st.pop_back();
        }

        if(closed < open) {
            st += ')';
            backtrack(open, closed+1, n, res, st);
            st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st;
        backtrack(0, 0, n, res, st);
        return res;
    }
};
