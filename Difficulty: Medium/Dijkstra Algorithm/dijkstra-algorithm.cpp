class Solution {
  public:
  const int INF = 1e9;
  typedef pair<int,int>P;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int Source) {
        
        // Convert edge list to adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // remove if graph is directed
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> distance(V, INF);
        distance[Source] = 0;
        pq.push({0, Source});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dist + edgeWeight < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }
};  