class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
          int n = pat.size(), m = txt.size();
        
        // dp[i][j] = true if first i chars of pattern match first j chars of text
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true; // Empty pattern matches empty text
        
        // Handle patterns like "*", "**", "***", etc.
        for (int i = 1; i <= n; i++) {
            if (pat[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];  // match single character
                else if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  
                    // '*' matches empty sequence (dp[i-1][j])
                    // or matches one more character (dp[i][j-1])
            }
        }
        
        return dp[n][m];
    }
};