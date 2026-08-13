class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {

        vector<vector<pair<int, int>>> graph(V);
        vector<int> indegree(V, 0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            graph[u].push_back({v, weight});
            indegree[v]++;
        }

        // Topological sort
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto &[next, weight] : graph[node]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Longest distance DP
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        for (int node : topo) {

            if (dist[node] == INT_MIN)
                continue;

            for (auto &[next, weight] : graph[node]) {

                dist[next] = max(
                    dist[next],
                    dist[node] + weight
                );
            }
        }

        return dist;
    }
};