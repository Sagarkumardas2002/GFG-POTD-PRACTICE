class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (int nbr : adj[node]) {
            if (!vis[nbr]) dfs(nbr, adj, vis);
        }
    }
    
    int minConnect(int V, vector<vector<int>>& edges) {
        
        // Create graph
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);
        int components = 0;

        // Count connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        int E = edges.size();
        int redundant = E - (V - components);

        // If not enough extra edges → impossible
        if (redundant < components - 1) return -1;

        // Otherwise, answer is components - 1
        return components - 1;
    }
};
