class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> adjRev[V];  // reversed graph
        vector<int> indegree(V, 0);
        
        // Step 1: Reverse the edges and calculate indegree
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adjRev[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        // Step 2: Push all terminal nodes (indegree = 0) into queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> safe;
        
        // Step 3: BFS (Topological sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (int neighbor : adjRev[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // Step 4: Sort the safe nodes before returning
        sort(safe.begin(), safe.end());
        return safe;
    }
};
