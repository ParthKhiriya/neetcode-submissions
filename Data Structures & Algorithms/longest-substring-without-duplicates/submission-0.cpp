class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0;
        int right = 0;

        unordered_set<char> count;
        int maxLength = 0;

        while(right < n) {
            while(count.find(s[right]) != count.end()) {
                count.erase(s[left]);
                left++;
            }
            count.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
