class Solution {
  public:

    // Function to build the string using split table
    string build(int i, int j, vector<vector<int>> &split) {
        if (i == j) {
            // Convert i -> character: A=0, B=1, ...
            char c = 'A' + (i - 1);
            return string(1, c);
        }

        int k = split[i][j];

        string left  = build(i, k, split);
        string right = build(k + 1, j, split);

        return "(" + left + right + ")";
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();

        // Number of matrices = n-1; matrices indexed 1 to n-1
        int m = n - 1;

        // dp[i][j] = minimum multiplications from matrix i to j
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        vector<vector<int>> split(m + 1, vector<int>(m + 1, 0));

        // gap = chain length
        for (int len = 2; len <= m; len++) {
            for (int i = 1; i + len - 1 <= m; i++) {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        // Build the final string
        return build(1, m, split);
    }
};
