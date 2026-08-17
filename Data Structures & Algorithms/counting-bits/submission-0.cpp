class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n+1, 0);

        for(int i=1; i<=n; i++) {
            int num = i;
            while(num != 0) {
                num = num & (num - 1);
                output[i]++;
            }
        }

        return output;
    }
};
