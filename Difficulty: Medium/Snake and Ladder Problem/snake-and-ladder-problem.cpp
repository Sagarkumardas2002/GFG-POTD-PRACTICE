class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        // jump[i] = destination if there is a snake/ladder at i
        vector<int> jump(N + 1, -1);

        // Store ladders
        for (int i = 0; i < lad.size(); i += 2) {
            int start = lad[i];
            int end = lad[i + 1];
            jump[start] = end;
        }

        // Store snakes
        for (int i = 0; i < sn.size(); i += 2) {
            int start = sn[i];
            int end = sn[i + 1];
            jump[start] = end;
        }

        // BFS
        queue<int> q;
        vector<int> dist(N + 1, -1);

        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Try all possible dice values: 1 to 6
            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > N)
                    continue;

                // Take snake/ladder immediately
                if (jump[next] != -1)
                    next = jump[next];

                // Visit only if not visited before
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;

                    if (next == N)
                        return dist[next];

                    q.push(next);
                }
            }
        }

        return -1;
    }
};