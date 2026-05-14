class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> res;

        for(auto& s: strs) {
            vector<int> count(26, 0);
            for(char c: s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1; i<26; i++) {
                // Starting from 1 because we have to add comma also, if we had started from 0, then the string would have started with a comma, and we don't want that.
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }

        for(auto& it: res) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
