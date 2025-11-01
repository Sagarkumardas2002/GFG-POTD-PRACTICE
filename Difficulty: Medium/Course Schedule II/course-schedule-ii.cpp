class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        adj.reserve(n);

        // Build graph: edge y -> x for [x, y]
        for (auto &p : prerequisites) {
            int x = p[0], y = p[1];
            adj[y].push_back(x);
            indeg[x]++;
        }

        queue<int> q;
        // start with all courses having no prerequisites
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> order;
        order.reserve(n);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        // If we were able to add all courses, return order; otherwise cycle -> empty
        if ((int)order.size() == n) return order;
        return {};
        
    }
};