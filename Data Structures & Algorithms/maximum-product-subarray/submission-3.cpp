class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int maxProd = INT_MIN;

        for(int i=0; i<n; i++) {
            int currProd = nums[i];
            maxProd = max(maxProd, currProd);
            for(int j=i+1; j<n; j++) {
                currProd *= nums[j];
                maxProd = max(maxProd, currProd);
            }
        }

        return maxProd;
    }
};
