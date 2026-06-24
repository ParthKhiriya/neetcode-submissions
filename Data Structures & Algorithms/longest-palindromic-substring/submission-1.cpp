class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int longestPalIdx = 0;
        int longestPalLen = 0;

        for(int i=0; i<n; i++) {
            // For odd length string
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > longestPalLen) {
                    longestPalIdx = left;
                    longestPalLen = right - left + 1;
                }
                left--;
                right++;
            }

            // For even length string
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > longestPalLen) {
                    longestPalIdx = left;
                    longestPalLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(longestPalIdx, longestPalLen);
    }
};
