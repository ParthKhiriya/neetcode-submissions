class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void backtrack(vector<string>& part, string& s, int i, int j) {
        if(i >= s.size()) {
            if(i == j) {
                result.push_back(part);
            }
            return;
        }

        if(isPalindrome(s, j, i)) {
            part.push_back(s.substr(j, i-j+1));
            backtrack(part, s, i+1, i+1);
            part.pop_back();
        }

        backtrack(part, s, i+1, j);
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;
        backtrack(part, s, 0, 0);
        return result;
    }
};
