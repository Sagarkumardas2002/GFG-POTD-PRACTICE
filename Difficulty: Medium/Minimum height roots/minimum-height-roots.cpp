class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        
        // Edge case
        if (V == 1) return {0};

        // Step 1: adjacency list + degree
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: push all leaf nodes
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Step 3: remove leaves layer by layer
        int remainingNodes = V;

        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    degree[neighbor]--;

                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Step 4: remaining nodes are answer
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};