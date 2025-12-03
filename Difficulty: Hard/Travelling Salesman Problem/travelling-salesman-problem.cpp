class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int mask, int pos, vector<vector<int>>& cost) {
        // If all cities visited, return cost to go back to city 0
        if (mask == (1 << n) - 1) 
            return cost[pos][0];

        // If already computed
        if (dp[mask][pos] != -1) 
            return dp[mask][pos];

        int ans = INT_MAX;

        // Try visiting every unvisited city
        for (int next = 0; next < n; next++) {
            if (!(mask & (1 << next))) {     // next city not visited
                int newMask = mask | (1 << next);
                ans = min(ans, cost[pos][next] + solve(newMask, next, cost));
            }
        }

        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));

        // Start from city 0 → mask = 1 (only 0 visited)
        return solve(1, 0, cost);
    }
};
