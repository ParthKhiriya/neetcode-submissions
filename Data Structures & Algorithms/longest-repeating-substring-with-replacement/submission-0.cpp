class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int ans = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for(char c: charSet) {
            int left = 0;
            int count = 0;
            for(int right=0; right<n; right++) {
                if(s[right] == c) count++;
                while(((right - left + 1) - count) > k) {
                    if(s[left] == c) count--;
                    left++;
                }

                ans = max(ans, right-left+1);
            }
        } 

        return ans;
    }
};
