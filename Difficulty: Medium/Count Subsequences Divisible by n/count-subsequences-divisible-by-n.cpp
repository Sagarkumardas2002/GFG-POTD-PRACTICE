class Solution {
    public:
      int countSubsequences(string& s, int n) {
          const int MOD = 1e9 + 7;

          vector<long long> dp(n, 0);

          for (char c : s) {
              int d = c - '0';

              // Subsequences formed by appending d
              vector<long long> ndp = dp;

              // Start a new subsequence with only this digit
              ndp[d % n] = (ndp[d % n] + 1) % MOD;

              // Append current digit to every existing subsequence
              for (int r = 0; r < n; r++) {
                  if (dp[r] == 0) continue;

                  int newR = (r * 10LL + d) % n;

                  ndp[newR] = (ndp[newR] + dp[r]) % MOD;
              }

              dp.swap(ndp);
          }

          return dp[0];
      }
  };