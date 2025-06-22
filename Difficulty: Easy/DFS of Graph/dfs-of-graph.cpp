class Solution {
  public:
    
    void dfs(vector<vector<int>>& adj,int node,  vector<int>&result, vector<bool>& visited ){
        
       // Base condition    
       if(visited[node] == true) return;    
        visited[node] = true;   // ✅ Mark the node as visited
        result.push_back(node); // Add it to the result
        
        // Recur for all the neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, neighbor, result, visited);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();   // Get the number of vertices
        vector<bool>visited(V,false); // Get the number of vertices
        vector<int>result;
        
        dfs(adj,0,result,visited);
        return result;
    }
};