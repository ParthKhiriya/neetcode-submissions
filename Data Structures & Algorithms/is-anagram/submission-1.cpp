class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        bool isAnagram = true;
        unordered_map<int, int> mpp;

        if(n != m) return false;

        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
            mpp[t[i]]--; 
        }

        for(int i=0; i<n; i++) {
            if(mpp[s[i]] != 0) isAnagram = false;
        }

        return isAnagram;
    }
};
