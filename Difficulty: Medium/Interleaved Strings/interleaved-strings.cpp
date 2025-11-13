class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
         int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        // Length check
        if (n1 + n2 != n3) return false;
        
        // dp[i][j] = true if s3[0...(i+j-1)] can be formed by 
        // interleaving s1[0...(i-1)] and s2[0...(j-1)]
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        
        dp[0][0] = true; // Empty strings case
        
        // Fill first row (using only s2)
        for (int j = 1; j <= n2; j++)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        
        // Fill first column (using only s1)
        for (int i = 1; i <= n1; i++)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        
        // Fill rest of dp table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                bool takeFromS1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool takeFromS2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[i][j] = takeFromS1 || takeFromS2;
            }
        }
        
        return dp[n1][n2];
        
    }
};