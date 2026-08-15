class Solution {
  public:
    int countWithout(int n, int d) {

        if (n == 0)
            return 0;

        string s = to_string(n);
        int len = s.size();

        long long dp[11][2][2] = {};

        dp[0][1][0] = 1;

        for (int pos = 0; pos < len; pos++) {

            for (int tight = 0; tight <= 1; tight++) {

                for (int started = 0; started <= 1; started++) {

                    if (dp[pos][tight][started] == 0)
                        continue;

                    int limit = tight ? s[pos] - '0' : 9;

                    for (int digit = 0; digit <= limit; digit++) {

                        // Don't allow d in an actual number
                        if ((started || digit != 0) && digit == d)
                            continue;

                        int newTight =
                            tight && (digit == s[pos] - '0');

                        int newStarted =
                            started || digit != 0;

                        dp[pos + 1][newTight][newStarted] +=
                            dp[pos][tight][started];
                    }
                }
            }
        }

        return dp[len][0][1] + dp[len][1][1];
    }
};