class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        vector<int> dp(n, 0);

        dp[0] = max(h[0], l[0]);

        for (int i = 1; i < n; i++) {
            // Low-effort today
            dp[i] = dp[i - 1] + l[i];

            // High-effort today
            if (i >= 2)
                dp[i] = max(dp[i], dp[i - 2] + h[i]);
            else
                dp[i] = max(dp[i], h[i]);

            // Do nothing is already covered by dp[i-1]
            dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};