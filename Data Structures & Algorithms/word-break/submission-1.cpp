class Solution {
public:
    unordered_map<int, bool> memo;

    bool dfs(string& s, vector<string>& wordDict, int i) {
        if(memo.find(i) != memo.end()) {
            return memo[i];
        }

        for(string sub: wordDict) {
            int len = sub.size();
            if((s.substr(i, len) == sub)) {
                if(dfs(s, wordDict, i+len)) {
                    memo[i] = dfs(s, wordDict, i+len);
                    return true;
                }
            }
        }

        memo[i] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0); // 0 is the starting index of recursion
    }
};
