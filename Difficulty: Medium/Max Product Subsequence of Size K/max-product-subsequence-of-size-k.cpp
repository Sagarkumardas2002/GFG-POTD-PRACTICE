class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();

        const long long INF = 1e18;

        vector<vector<long long>> mx(n + 1, vector<long long>(k + 1, -INF));
        vector<vector<long long>> mn(n + 1, vector<long long>(k + 1, INF));

        mx[0][0] = 1;
        mn[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int x = arr[i - 1];

            for (int j = 0; j <= min(i, k); j++) {

                // Do not take arr[i-1]
                if (j <= i - 1) {
                    mx[i][j] = max(mx[i][j], mx[i - 1][j]);
                    mn[i][j] = min(mn[i][j], mn[i - 1][j]);
                }

                // Take arr[i-1]
                if (j > 0 && mx[i - 1][j - 1] != -INF) {
                    long long a = mx[i - 1][j - 1] * x;
                    long long b = mn[i - 1][j - 1] * x;

                    mx[i][j] = max(mx[i][j], max(a, b));
                    mn[i][j] = min(mn[i][j], min(a, b));
                }
            }
        }

        return (int)mx[n][k];
    }
};