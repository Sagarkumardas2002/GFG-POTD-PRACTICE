class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        
        // dp[i][j] = minimum cost of BST using keys[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Prefix sum of frequencies to get range sum quickly
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + freq[i];
        
        auto sum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };
        
        // Fill dp for increasing length of interval
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                // Base case: single key
                if (i == j) {
                    dp[i][j] = freq[i];
                    continue;
                }
                
                int best = INT_MAX;
                
                // Try each key as root
                for (int k = i; k <= j; k++) {
                    int left  = (k > i) ? dp[i][k - 1] : 0;
                    int right = (k < j) ? dp[k + 1][j] : 0;
                    
                    int cost = left + right;
                    best = min(best, cost);
                }
                
                dp[i][j] = best + sum(i, j);
            }
        }
        
        return dp[0][n - 1];
    }
};
