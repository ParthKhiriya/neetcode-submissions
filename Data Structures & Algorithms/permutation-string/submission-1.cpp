class Solution {
public:
    bool isAnagram(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        if(n != m) return false;

        unordered_map<char, int> count;

        for(int i=0; i<n; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }

        for(auto it: count) {
            if(it.second > 0) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();

        // Now we have to iterate through s2, to take all its substrings of size k
        int left = 0;
        int right = k-1;

        while(right < n) {
            string sub = s2.substr(left, k);
            if(isAnagram(s1, sub)) {
                return true;
            }
            left++;
            right++;
        }

        return false;
    }
};
