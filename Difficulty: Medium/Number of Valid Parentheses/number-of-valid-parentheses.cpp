class Solution {
  public:
    int findWays(int n) {
        // If length is odd, no valid parentheses possible
        if (n % 2 != 0) return 0;
        
        int pairs = n / 2;
        
        // dp[i] will store Catalan number for i pairs
        vector<long long> dp(pairs + 1, 0);
        
        dp[0] = 1; // Base case
        
        for (int i = 1; i <= pairs; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        
        return dp[pairs];
    }
};
