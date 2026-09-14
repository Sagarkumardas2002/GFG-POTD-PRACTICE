class Solution {
  public:

    bool isSafe(vector<vector<int>> &mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        // Outside matrix
        if (r < 0 || r >= n || c < 0 || c >= m)
            return false;

        // Not a safe cell
        if (mat[r][c] != 1)
            return false;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // Check whether this cell is adjacent to a landmine
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                mat[nr][nc] == 0) {
                return false;
            }
        }

        return true;
    }

    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<array<int, 3>> q;

        // Put all safe cells of first column into queue
        // Distance starts from 1 because GFG counts cells
        for (int i = 0; i < n; i++) {
            if (isSafe(mat, i, 0)) {
                q.push({i, 0, 1});

                // Mark visited
                mat[i][0] = -1;
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int dist = cur[2];

            // Reached last column
            if (c == m - 1) {
                return dist;
            }

            // Try 4 directions
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isSafe(mat, nr, nc)) {
                    q.push({nr, nc, dist + 1});

                    // Mark visited
                    mat[nr][nc] = -1;
                }
            }
        }

        return -1;
    }
};