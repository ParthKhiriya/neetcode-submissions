class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        int left = 0;
        int right = 1;

        while(right < n) {
            if(prices[right] > prices[left]) {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            } else {
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};
