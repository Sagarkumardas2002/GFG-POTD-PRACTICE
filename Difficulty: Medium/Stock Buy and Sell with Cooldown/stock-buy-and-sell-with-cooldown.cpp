class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int holdStock = -prices[0];     // Profit if we currently hold a stock
        int noStock = 0;                // Profit if we don’t hold any stock
        int prevNoStock = 0;            // Profit two days before (for cooldown)

        for (int day = 1; day < n; day++) {
            int newHoldStock = max(holdStock, prevNoStock - prices[day]);  // buy or keep holding
            int newNoStock = max(noStock, holdStock + prices[day]);        // sell or do nothing

            prevNoStock = noStock;  // move cooldown reference
            holdStock = newHoldStock;
            noStock = newNoStock;
        }

        return noStock;  // max profit when not holding any stock at the end
    }
};
