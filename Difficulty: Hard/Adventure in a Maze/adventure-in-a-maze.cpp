class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        
        const int MOD = 1000000007;
        int n = grid.size();

        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<int>> adventure(n, vector<int>(n, -1));

        ways[0][0] = 1;
        adventure[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (adventure[i][j] == -1)
                    continue;

                // Move Right
                if ((grid[i][j] == 1 || grid[i][j] == 3) &&
                    j + 1 < n) {

                    ways[i][j + 1] =
                        (ways[i][j + 1] + ways[i][j]) % MOD;

                    adventure[i][j + 1] =
                        max(adventure[i][j + 1],
                            adventure[i][j] + grid[i][j + 1]);
                }

                // Move Down
                if ((grid[i][j] == 2 || grid[i][j] == 3) &&
                    i + 1 < n) {

                    ways[i + 1][j] =
                        (ways[i + 1][j] + ways[i][j]) % MOD;

                    adventure[i + 1][j] =
                        max(adventure[i + 1][j],
                            adventure[i][j] + grid[i + 1][j]);
                }
            }
        }

        int totalPaths = ways[n - 1][n - 1];

        int maxAdventure = adventure[n - 1][n - 1];

        if (maxAdventure == -1)
            maxAdventure = 0;

        return {totalPaths, maxAdventure};
    }
};