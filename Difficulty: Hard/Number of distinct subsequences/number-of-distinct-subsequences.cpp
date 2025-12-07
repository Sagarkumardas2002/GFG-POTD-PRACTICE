class Solution {
public:
    static const int MOD = 1e9 + 7;

    int distinctSubseq(string &str) {
        int n = str.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // empty subsequence

        vector<int> last(26, -1);  // last index of character

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;

            int ch = str[i - 1] - 'a';

            if (last[ch] != -1) {
                int j = last[ch];
                dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;  // subtract duplicates
            }

            last[ch] = i;
        }

        return dp[n];
    }
};
