class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";

        string result = "";
        int maxLen = 0;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int currentLen = j-i+1;
                string sub = s.substr(i, currentLen);
                
                if(currentLen > maxLen && isPalindrome(sub)) {
                    maxLen = currentLen;
                    result = sub;
                }
            }
        }

        return result;
    }

private: 
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left <= right) {
            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
