class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        // Min heap -> {cost, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<bool> visited(n, false);
        int totalCost = 0;
        
        pq.push({0, 0}); // start from node 0
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int cost = it.first;
            int node = it.second;
            
            if (visited[node]) continue;
            
            visited[node] = true;
            totalCost += cost;
            
            // check all other nodes
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(houses[node][0] - houses[i][0]) +
                               abs(houses[node][1] - houses[i][1]);
                    
                    pq.push({dist, i});
                }
            }
        }
        
        return totalCost;
    }
};