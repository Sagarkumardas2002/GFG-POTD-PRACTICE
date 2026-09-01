class Solution {
  public:
      int palindromicStrings(int n, int k) {
          const long long MOD = 1000000007;

          long long ans = 0;
          long long perm = 1;  // P(k, 0)

          for (int m = 0; m <= k; m++) {

              // Odd length = 2*m + 1
              if (2 * m + 1 <= n) {
                  ans = (ans + perm * (k - m)) % MOD;
              }

              // Even length = 2*m
              if (m > 0 && 2 * m <= n) {
                  ans = (ans + perm) % MOD;
              }

              // Prepare P(k, m+1)
              if (m < k) {
                  perm = (perm * (k - m)) % MOD;
              }
          }

          return ans;
      }
  };