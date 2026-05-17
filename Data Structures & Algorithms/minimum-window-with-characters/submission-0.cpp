class Solution {
public:
    string minWindow(string s, string t) {
        // This question is of Sliding window(variable window size) pattern.
        int n = s.size();
        int k = t.size();
        if (k > n || k == 0) return "";

        vector<int> countT(128, 0);
        for(int i=0; i<k; i++) {
            countT[t[i]]++;
        }

        int left = 0;
        int required = k;

        int minLen = INT_MAX;
        int minStart = 0;

        for(int right=0; right<n; right++) {
            if(countT[s[right]] > 0) {
                required--;
            }
            countT[s[right]]--;

            while(required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                countT[s[left]]++;

                if (countT[s[left]] > 0) {
                    required++;
                }
                
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
