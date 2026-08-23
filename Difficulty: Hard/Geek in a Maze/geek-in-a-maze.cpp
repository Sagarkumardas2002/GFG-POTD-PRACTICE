class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(m, INF));

        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_front({r, c});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!dq.empty()) {

            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n ||
                    ny < 0 || ny >= m ||
                    mat[nx][ny] == '#') {
                    continue;
                }

                int cost;

                // Moving UP increases upward moves
                if (nx == x - 1)
                    cost = 1;
                else
                    cost = 0;

                if (dist[x][y] + cost < dist[nx][ny]) {

                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dist[i][j] == INF)
                    continue;

                int upMoves = dist[i][j];

                int downMoves = upMoves + (i - r);

                if (upMoves <= u && downMoves <= d) {
                    answer++;
                }
            }
        }

        return answer;
    }
};