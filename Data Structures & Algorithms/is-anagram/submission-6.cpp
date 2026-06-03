class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        vector<int> check(26, 0);

        for(int i=0; i<n; i++) {
            check[s[i] - 'a']++;
            check[t[i] - 'a']--;
        }

        for(int val: check) {
            if(val != 0) return false;
        }

        return true;
    }
};
