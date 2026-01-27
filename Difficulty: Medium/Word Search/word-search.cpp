class Solution {
public:
    int n, m;
    
    bool dfs(int row, int col, int idx, vector<vector<char>> &mat, string &word) {
        // All characters matched
        if (idx == word.size())
            return true;

        // Boundary & character check
        if (row < 0 || col < 0 || row >= n || col >= m || mat[row][col] != word[idx])
            return false;

        char temp = mat[row][col];
        mat[row][col] = '#';   // mark visited

        // Explore 4 directions
        bool found =
            dfs(row + 1, col, idx + 1, mat, word) ||
            dfs(row - 1, col, idx + 1, mat, word) ||
            dfs(row, col + 1, idx + 1, mat, word) ||
            dfs(row, col - 1, idx + 1, mat, word);

        mat[row][col] = temp;  // backtrack
        return found;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, mat, word))
                    return true;
            }
        }
        return false;
    }
};
