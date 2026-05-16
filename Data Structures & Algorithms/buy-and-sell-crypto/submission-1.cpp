class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        vector<int> leftMin(n);
        leftMin[0] = prices[0];

        for(int i=1; i<n; i++) {
            leftMin[i] = min(leftMin[i-1], prices[i]);
        }

        for(int i=0; i<n; i++) {
            int profit = prices[i] - leftMin[i];
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
};
