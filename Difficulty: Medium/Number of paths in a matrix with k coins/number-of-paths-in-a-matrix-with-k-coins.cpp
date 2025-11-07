class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        // 3D DP: dp[i][j][sum] = number of ways to reach (i,j) with sum = sum
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        // Base case
        if (mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;

        // Fill the DP table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int coins = mat[i][j]; coins <= k; coins++) {
                    // Skip the starting cell, already initialized
                    if (i == 0 && j == 0) continue;

                    int ways = 0;
                    if (i > 0) ways += dp[i - 1][j][coins - mat[i][j]];
                    if (j > 0) ways += dp[i][j - 1][coins - mat[i][j]];

                    dp[i][j][coins] = ways;
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};
