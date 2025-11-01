class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
         long long E = edges.size();
        long long maxPossible = 1LL * V * (V - 1) / 2; // maximum edges in a DAG following a topo order
        long long ans = maxPossible - E;
        return static_cast<int>(ans);
        
    }
};
