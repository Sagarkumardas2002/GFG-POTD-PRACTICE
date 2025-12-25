class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            // Find row index of maximum element in mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int leftVal  = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1e9;
            int rightVal = (midCol + 1 < m)  ? mat[maxRow][midCol + 1] : -1e9;

            // Check peak condition
            if (mat[maxRow][midCol] >= leftVal &&
                mat[maxRow][midCol] >= rightVal) {
                return {maxRow, midCol};
            }
            else if (leftVal > mat[maxRow][midCol]) {
                right = midCol - 1;
            }
            else {
                left = midCol + 1;
            }
        }

        return {-1, -1}; // fallback (won't happen as peak always exists)
    }
};
