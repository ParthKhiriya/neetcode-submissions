class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        
        int leftMin;
        leftMin = prices[0];
        
        for(int i=1; i<n; i++) {
            leftMin = min(leftMin, prices[i]);
            int profit = prices[i] - leftMin;
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
};
