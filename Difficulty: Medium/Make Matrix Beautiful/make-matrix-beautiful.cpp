class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        int total = 0, maxSum = 0;
    
        // Calculate row and column sums
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
                total += mat[i][j];
            }
        }
    
        // Find the maximum sum among rows and columns
        for (int i = 0; i < n; ++i) {
            maxSum = max({maxSum, rowSum[i], colSum[i]});
        }
    
        // Return total operations needed
        return maxSum * n - total;
    }
};