class Solution {
    const int MOD = 1e9 + 7;

public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time}); // Undirected edge
        }

        long long INF = numeric_limits<long long>::max();
        vector<long long> dist(V, INF);
        vector<int> ways(V, 0);

        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        // Initialization for the source node 0
        dist[0] = 0;
        ways[0] = 1; // There is 1 way to reach the source node (itself)
        pq.push({0, 0}); // {time, node}

        // 4. Run Dijkstra's Algorithm
        while (!pq.empty()) {
            long long time_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: If the extracted time is already greater than the known shortest distance, skip.
            if (time_u > dist[u]) {
                continue;
            }

            // Explore neighbors of u
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int time_uv = edge.second;
                long long new_time = time_u + time_uv;

                // Case 1: Found a *strictly* shorter path to v
                if (new_time < dist[v]) {
                    dist[v] = new_time; // Update shortest time
                    ways[v] = ways[u]; // The number of ways is now the ways to u
                    pq.push({new_time, v}); // Enqueue new shorter path
                } 
                
                // Case 2: Found a path with the *same* shortest time to v
                else if (new_time == dist[v]) {
                    // This path contributes to the total number of shortest paths.
                    // Add the ways to reach u to the ways to reach v.
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V - 1];
  
        
    }
};