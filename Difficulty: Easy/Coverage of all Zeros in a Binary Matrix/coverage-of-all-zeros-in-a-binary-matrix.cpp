class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int result = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (mat[row][col] == 0) {

                    // Check Left
                    for (int j = col - 1; j >= 0; j--) {
                        if (mat[row][j] == 1) {
                            result++;
                            break;
                        }
                    }

                    // Check Right
                    for (int j = col + 1; j < m; j++) {
                        if (mat[row][j] == 1) {
                            result++;
                            break;
                        }
                    }

                    // Check Up
                    for (int i = row - 1; i >= 0; i--) {
                        if (mat[i][col] == 1) {
                            result++;
                            break;
                        }
                    }

                    // Check Down
                    for (int i = row + 1; i < n; i++) {
                        if (mat[i][col] == 1) {
                            result++;
                            break;
                        }
                    }
                }
            }
        }

        return result;
    }
};