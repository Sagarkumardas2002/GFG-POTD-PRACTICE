class Solution {
public:
    int minCost(string &s, string &t,
                vector<vector<char>> &transform,
                vector<int> &cost) {

        const int INF = 1e9;

        // 26x26 matrix initialized with INF
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // cost to remain same is zero
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // fill direct transformation costs
        for (int i = 0; i < transform.size(); i++) {
            int from = transform[i][0] - 'a';
            int to   = transform[i][1] - 'a';
            dist[from][to] = min(dist[from][to], cost[i]);
        }

        // Floyd–Warshall for shortest paths
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        long long totalCost = 0;

        // Process each character of s & t
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;

            int a = s[i] - 'a';
            int b = t[i] - 'a';

            int best = INF;

            // try making both chars equal to some common letter k
            for (int k = 0; k < 26; k++) {
                if (dist[a][k] < INF && dist[b][k] < INF) {
                    best = min(best, dist[a][k] + dist[b][k]);
                }
            }

            if (best == INF) return -1; // impossible

            totalCost += best;
        }

        return totalCost;
    }
};
