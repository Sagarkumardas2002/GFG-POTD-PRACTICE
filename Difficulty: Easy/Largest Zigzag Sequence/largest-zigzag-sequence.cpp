class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        // n = 1 -> only one element can be selected
        if (n == 1)
            return mat[0][0];

        vector<int> dp(n);

        // First row
        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++) {

            // Find largest and second largest in previous row
            int max1 = -1;
            int max2 = -1;
            int idx = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > max1) {
                    max2 = max1;
                    max1 = dp[j];
                    idx = j;
                }
                else if (dp[j] > max2) {
                    max2 = dp[j];
                }
            }

            vector<int> newDp(n);

            for (int j = 0; j < n; j++) {

                // Cannot choose the same column
                if (j == idx)
                    newDp[j] = mat[i][j] + max2;
                else
                    newDp[j] = mat[i][j] + max1;
            }

            dp = newDp;
        }

        // Maximum value in last row
        return *max_element(dp.begin(), dp.end());
    }
};