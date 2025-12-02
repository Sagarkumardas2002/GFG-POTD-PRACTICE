class Solution {
public:
    int maxScore(string s, vector<vector<char>>& jumps) {

        int n = s.length();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (long long)s[i];
        }

        vector<vector<long long>> charPrefix(26, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            for (int ch = 0; ch < 26; ch++)
                charPrefix[ch][i + 1] = charPrefix[ch][i];
            charPrefix[c][i + 1] += (long long)s[i];
        }

        vector<vector<bool>> canJump(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++) canJump[i][i] = true;

        for (auto &p : jumps) {
            int src = p[0] - 'a';
            int dest = p[1] - 'a';
            canJump[src][dest] = true;
        }

        vector<vector<long long>> best(26, vector<long long>(26, LLONG_MIN));
        vector<long long> dp(n, LLONG_MIN);

        dp[0] = 0;
        int firstChar = s[0] - 'a';

        for (int dest = 0; dest < 26; dest++)
            best[firstChar][dest] = 0 - prefix[0] + charPrefix[dest][0];

        for (int i = 1; i < n; i++) {
            int currChar = s[i] - 'a';
            long long maxVal = LLONG_MIN;

            for (int src = 0; src < 26; src++) {
                if (canJump[src][currChar] && best[src][currChar] != LLONG_MIN) {
                    maxVal = max(maxVal, best[src][currChar]);
                }
            }

            if (maxVal != LLONG_MIN) {
                dp[i] = maxVal + (prefix[i] - charPrefix[currChar][i]);
            }

            if (dp[i] != LLONG_MIN) {
                for (int dest = 0; dest < 26; dest++) {
                    long long val = dp[i] - prefix[i] + charPrefix[dest][i];
                    best[currChar][dest] = max(best[currChar][dest], val);
                }
            }
        }

        long long ans = 0;
        for (long long x : dp) ans = max(ans, x);

        return (int)ans;
    }
};
