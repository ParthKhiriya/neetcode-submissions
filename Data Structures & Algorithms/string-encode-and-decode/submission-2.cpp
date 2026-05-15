#include<string>
#include<bits/stdc++.h>

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& s: strs) {
            int length = s.size();
            encoded += to_string(length) + '#' + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            decoded.push_back(s.substr(i, length));
            i = i + length;
        }

        return decoded;
    }
};