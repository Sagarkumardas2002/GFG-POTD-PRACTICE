class Solution {
  public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        
        // Check possibility
        if ((n - 1) % (k - 1) != 0) return -1;

        // Prefix sum for range sum queries
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        // dp[i][j][m] = min cost to merge stones[i..j] into m piles
        const int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INF)));

        // Base case: merging a single pile
        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        // Length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                // For piles m = 2 to k
                for (int m = 2; m <= k; m++) {
                    for (int mid = i; mid < j; mid += (k - 1)) {
                        if (dp[i][mid][1] == INF || dp[mid + 1][j][m - 1] == INF) continue;
                        dp[i][j][m] = min(dp[i][j][m],
                                          dp[i][mid][1] + dp[mid + 1][j][m - 1]);
                    }
                }

                // If we can merge k piles → make 1 pile
                if (dp[i][j][k] != INF) {
                    dp[i][j][1] = dp[i][j][k] + prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1][1];
    }
};