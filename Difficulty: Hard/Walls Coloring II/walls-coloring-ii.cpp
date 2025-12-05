class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int k = costs[0].size();
        if (k == 0) return -1;

        // If only one color but more than one wall => impossible
        if (k == 1 && n > 1) return -1;

        vector<int> dp(k), newdp(k);

        // Initialize dp with first wall
        for (int c = 0; c < k; c++) dp[c] = costs[0][c];

        for (int i = 1; i < n; i++) {

            // Find smallest and second smallest in dp
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;

            for (int c = 0; c < k; c++) {
                if (dp[c] < min1) {
                    min2 = min1;
                    min1 = dp[c];
                    idx1 = c;
                } else if (dp[c] < min2) {
                    min2 = dp[c];
                }
            }

            // Build dp for wall i
            for (int c = 0; c < k; c++) {
                if (c == idx1) {
                    newdp[c] = costs[i][c] + min2;
                } else {
                    newdp[c] = costs[i][c] + min1;
                }
            }

            dp = newdp;
        }

        // Final minimum cost
        return *min_element(dp.begin(), dp.end());
    }
};
