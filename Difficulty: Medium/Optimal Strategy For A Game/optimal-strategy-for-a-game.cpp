class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // length = 1 (same index)
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }

        // fill DP for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                long long pickLeft = arr[i] + min(
                    (i + 2 <= j) ? dp[i + 2][j] : 0,
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0
                );

                long long pickRight = arr[j] + min(
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0,
                    (i <= j - 2) ? dp[i][j - 2] : 0
                );

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1];
    }
};
