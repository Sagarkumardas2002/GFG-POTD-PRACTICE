class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& mat, int i1, int j1, int i2) {
        int j2 = i1 + j1 - i2; // since steps are equal
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n || 
            mat[i1][j1] == -1 || mat[i2][j2] == -1)
            return INT_MIN; // invalid path
        
        if (i1 == n - 1 && j1 == n - 1)
            return mat[i1][j1]; // reached destination
        
        if (dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];
        
        int chocolates = 0;
        if (i1 == i2 && j1 == j2)
            chocolates += mat[i1][j1]; // same cell, count once
        else
            chocolates += mat[i1][j1] + mat[i2][j2];
        
        int temp = max({
            solve(mat, i1 + 1, j1, i2 + 1), // down, down
            solve(mat, i1, j1 + 1, i2),     // right, right
            solve(mat, i1 + 1, j1, i2),     // down, right
            solve(mat, i1, j1 + 1, i2 + 1)  // right, down
        });
        
        chocolates += temp;
        return dp[i1][j1][i2] = chocolates;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = solve(mat, 0, 0, 0);
        return max(0, ans); // if no valid path, return 0
    }
};