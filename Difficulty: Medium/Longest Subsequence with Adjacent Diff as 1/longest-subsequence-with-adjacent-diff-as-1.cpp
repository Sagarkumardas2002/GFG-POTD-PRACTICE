class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        const int MAX = 1000000;

        vector<int> dp(MAX + 2, 0);
        int ans = 0;

        for (int x : arr) {
            int curr = max(dp[x - 1], dp[x + 1]) + 1;

            // Important: don't overwrite a larger value
            dp[x] = max(dp[x], curr);

            ans = max(ans, dp[x]);
        }

        return ans;
    }
};