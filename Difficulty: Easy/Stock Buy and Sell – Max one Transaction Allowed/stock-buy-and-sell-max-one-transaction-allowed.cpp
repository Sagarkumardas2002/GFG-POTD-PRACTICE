class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minimumPriceSoFar = prices[0];
        int maximumProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int currentProfit = prices[i] - minimumPriceSoFar;
            maximumProfit = max(maximumProfit, currentProfit);
            minimumPriceSoFar = min(minimumPriceSoFar, prices[i]);
        }

        return maximumProfit;
    }
};

