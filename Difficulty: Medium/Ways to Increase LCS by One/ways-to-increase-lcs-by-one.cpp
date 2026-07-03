class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

        // Prefix LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp1[i][j] = 1 + dp1[i - 1][j - 1];
                else
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
            }
        }

        // Suffix LCS
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp2[i][j] = 1 + dp2[i + 1][j + 1];
                else
                    dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
            }
        }

        int lcs = dp1[n][m];
        int ans = 0;

        for (int pos = 0; pos <= n; pos++) {

            for (char ch = 'a'; ch <= 'z'; ch++) {

                bool ok = false;

                for (int k = 0; k < m; k++) {

                    if (s2[k] != ch)
                        continue;

                    if (dp1[pos][k] + dp2[pos][k + 1] == lcs) {
                        ok = true;
                        break;
                    }
                }

                if (ok)
                    ans++;
            }
        }

        return ans;
    }
};