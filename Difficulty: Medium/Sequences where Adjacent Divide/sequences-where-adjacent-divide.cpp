class Solution {
  public:
    int count(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case
        for (int x = 1; x <= m; x++)
            dp[1][x] = 1;

        // DP transitions
        for (int len = 2; len <= n; len++) {
            for (int x = 1; x <= m; x++) {
                for (int y = 1; y <= m; y++) {
                    if (x % y == 0 || y % x == 0)
                        dp[len][x] += dp[len - 1][y];
                }
            }
        }

        int ans = 0;
        for (int x = 1; x <= m; x++)
            ans += dp[n][x];

        return ans;
    }
};