class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        // 8 directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                // Starting cell must match first character
                if (mat[r][c] != word[0])
                    continue;

                // Try all 8 directions
                for (int d = 0; d < 8; d++) {
                    int nr = r;
                    int nc = c;
                    int k = 0;

                    while (k < word.size()) {
                        // Out of bounds
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                            break;

                        // Character mismatch
                        if (mat[nr][nc] != word[k])
                            break;

                        nr += dr[d];
                        nc += dc[d];
                        k++;
                    }

                    // Entire word found
                    if (k == word.size()) {
                        ans.push_back({r, c});
                        break;  // Don't add same starting cell again
                    }
                }
            }
        }

        return ans;
    }
};