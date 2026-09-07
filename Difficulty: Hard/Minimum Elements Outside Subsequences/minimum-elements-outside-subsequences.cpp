class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[i][j]:
        // maximum number of elements selected so far
        // where i is the last index of increasing subsequence
        // and j is the last index of decreasing subsequence.
        //
        // -1 means that the corresponding subsequence is empty.
        const int EMPTY = n;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        dp[EMPTY][EMPTY] = 0;

        for (int k = 0; k < n; k++) {
            vector<vector<int>> ndp = dp;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {

                    if (dp[i][j] == -1)
                        continue;

                    int incLast = (i == EMPTY ? -1 : arr[i]);
                    int decLast = (j == EMPTY ? 101 : arr[j]);

                    // Put arr[k] in increasing subsequence
                    if (i == EMPTY || arr[k] > incLast) {
                        ndp[k][j] = max(ndp[k][j],
                                        dp[i][j] + 1);
                    }

                    // Put arr[k] in decreasing subsequence
                    if (j == EMPTY || arr[k] < decLast) {
                        ndp[i][k] = max(ndp[i][k],
                                        dp[i][j] + 1);
                    }

                    // Leave arr[k] unused
                    ndp[i][j] = max(ndp[i][j], dp[i][j]);
                }
            }

            dp.swap(ndp);
        }

        int maximumSelected = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maximumSelected = max(maximumSelected, dp[i][j]);
            }
        }

        return n - maximumSelected;
    }
};