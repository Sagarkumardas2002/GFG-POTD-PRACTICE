
class Solution {
    typedef pair<int,int>P;
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Min-heap to always pick the edge with the smallest weight
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0,0});// Start with node 0 and weight 0

        vector<bool>inMST(V,false); // Track nodes already included in MST
        
        int totalWeight =0; // Store the total weight of MST
        
        while(!pq.empty()){
            auto p=pq.top();    
            pq.pop();
            
            int weight=p.first;
            int node=p.second;
            
            if(inMST[node]==true) continue; // If the node is already in MST, skip it
            
            // Include the node in MST and add the edge weight
            inMST[node]=true;
            totalWeight +=weight;
            
            
              // Check all adjacent nodes of the current node
            for(auto &edge:adj[node]){
                int neighborNode =edge[0];
                int neighborWeight =edge[1];
                
                // If adjacent node is not in MST, push it to the heap
                if(inMST[neighborNode]==false){
                    pq.push({neighborWeight ,neighborNode});
                }
            }
        }
        
        return totalWeight ;
        
    }
};