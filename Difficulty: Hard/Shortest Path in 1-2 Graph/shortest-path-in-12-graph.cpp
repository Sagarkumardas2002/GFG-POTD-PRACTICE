class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto &[next, wt] : adj[node]) {
                if (d + wt < dist[next]) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return (dist[dest] == INT_MAX) ? -1 : dist[dest];
    }
};