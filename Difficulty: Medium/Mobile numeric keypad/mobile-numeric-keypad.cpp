class Solution {
  public:
    int solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp) {
        if (i < 0 || j < 0 || i > 3 || j > 2 || mat[i][j] == -1) return 0;
        if (n == 0) return 1;
        if (dp[i][j][n] != -1) return dp[i][j][n];

        int ans = solve(i, j, n - 1, mat, dp) +   // stay
                  solve(i + 1, j, n - 1, mat, dp) + // down
                  solve(i - 1, j, n - 1, mat, dp) + // up
                  solve(i, j + 1, n - 1, mat, dp) + // right
                  solve(i, j - 1, n - 1, mat, dp);  // left

        return dp[i][j][n] = ans;
    }

    int getCount(int n) {
        vector<vector<int>> mat = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {-1, 1, -1}
        };

        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        int count = 0;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (mat[i][j] != -1)
                    count += solve(i, j, n - 1, mat, dp);
            }
        }

        return count;
    }
};
