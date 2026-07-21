class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> dp(n);
        vector<int> best(26, -1);

        int ans = -1;
        bool hasA = false;

        for (int i = n - 1; i >= 0; i--) {
            int cur = s[i] - 'a';

            dp[i] = i;

            if (cur < 25 && best[cur + 1] != -1)
                dp[i] = best[cur + 1];

            best[cur] = max(best[cur], dp[i]);

            if (cur == 0) {
                hasA = true;
                ans = max(ans, dp[i] - i);
            }
        }

        return hasA ? ans : -1;
    }
};