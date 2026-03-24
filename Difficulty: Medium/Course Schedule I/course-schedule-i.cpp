class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Step 1: Build graph
        for(auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Queue for BFS
        queue<int> q;
        
        // Step 3: Push nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        // Step 4: BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 5: Check if all nodes processed
        return count == n;
    }
};