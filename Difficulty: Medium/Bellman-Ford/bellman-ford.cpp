// User function Template for C++

class Solution {
  public:
    int INF=1e8;
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
      
      vector<int>result(V,INF);
      result[src]=0;
      
      for(int i=0;i<V-1;i++){
          for(auto edge:edges){
               int u = edge[0];
               int v = edge[1];
               int weight = edge[2];
            if(result[u]!=INF && result[u]+weight<result[v]){
                result[v]=weight+result[u];
            }
          }
      }
      
       //Now detect negative cycle
        for(auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if(result[u] != INF && result[u] + weight < result[v]) {
                return {-1};
            }
        }
        
        return result;
    }
};
 