class Solution {
    typedef pair<int,int>P;
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
          priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0,0});
        vector<bool>inMST(V,false);
        int sum=0;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int weight=p.first;
            int node=p.second;
            
            if(inMST[node]==true){
                continue;
            }
            
            inMST[node]=true;
            sum+=weight;
            
            for(auto &temp:adj[node]){
                int neighbour=temp[0];
                int neighbour_weight=temp[1];
                
                if(inMST[neighbour]==false){
                    pq.push({neighbour_weight,neighbour});
                }
            }
        }
        return sum;
        
    }
};