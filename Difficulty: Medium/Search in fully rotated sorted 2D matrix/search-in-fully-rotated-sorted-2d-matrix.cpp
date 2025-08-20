class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n, col = mid % n;
            int val = mat[row][col];

            if (val == x) return true;

            // find left and right values for rotation logic
            int leftVal = mat[left / n][left % n];
            int rightVal = mat[right / n][right % n];

            // Left half is sorted
            if (leftVal <= val) {
                if (leftVal <= x && x < val) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (val < x && x <= rightVal) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
