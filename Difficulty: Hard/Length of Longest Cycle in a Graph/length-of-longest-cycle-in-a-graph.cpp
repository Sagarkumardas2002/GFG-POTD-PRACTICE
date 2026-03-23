class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj(V, -1);
        
        // convert edges to single outgoing format
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            
            if (visited[i]) continue;
            
            unordered_map<int, int> step; // node -> step count
            int node = i;
            int cnt = 0;
            
            while (node != -1) {
                
                // if already visited in this traversal → cycle found
                if (step.count(node)) {
                    ans = max(ans, cnt - step[node]);
                    break;
                }
                
                // if visited before in some other traversal → no cycle here
                if (visited[node]) break;
                
                visited[node] = 1;
                step[node] = cnt;
                cnt++;
                
                node = adj[node];
            }
        }
        
        return ans;
    }
};