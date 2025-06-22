class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();            // Number of vertices in the graph
        vector<int> bfsTraversal;      // Stores the BFS traversal result
        vector<bool> visited(V, false); // Keeps track of visited nodes
        queue<int> q;                  // Queue for BFS traversal

        // Start BFS from node 0 (as per convention)
        q.push(0);         
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();  // Get the front node in the queue
            q.pop();
            bfsTraversal.push_back(node); // Add it to the traversal result

            // Visit all adjacent (neighbor) nodes
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);        // Enqueue unvisited neighbors
                    visited[neighbor] = true; // Mark as visited
                }
            }
        }

        return bfsTraversal;
    }
};








