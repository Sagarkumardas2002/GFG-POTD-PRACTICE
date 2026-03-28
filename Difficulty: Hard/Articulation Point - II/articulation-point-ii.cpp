class Solution {
  public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited,
             vector<int>& tin, vector<int>& low, vector<int>& mark, int &timer) {
        
        visited[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!visited[it]) {
                dfs(it, node, adj, visited, tin, low, mark, timer);
                
                low[node] = min(low[node], low[it]);

                // Case 2: Non-root node
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } 
            else {
                // Back edge
                low[node] = min(low[node], tin[it]);
            }
        }

        // Case 1: Root node
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(V, 0), tin(V), low(V), mark(V, 0);
        int timer = 0;

        // Step 2: Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, tin, low, mark, timer);
            }
        }

        // Step 3: Collect result
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) result.push_back(i);
        }

        if (result.size() == 0) return {-1};
        return result;
    }
};