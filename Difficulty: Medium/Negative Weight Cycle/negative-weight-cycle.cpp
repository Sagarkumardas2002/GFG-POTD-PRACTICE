class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>> edges) {

        vector<long long> dist(V, 0);

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {

            bool updated = false;

            for (auto &edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;
                    updated = true;
                }
            }

            // No update means no negative cycle
            if (!updated)
                return false;
        }

        // One extra relaxation
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] + weight < dist[v]) {
                return true;
            }
        }

        return false;
    }
};