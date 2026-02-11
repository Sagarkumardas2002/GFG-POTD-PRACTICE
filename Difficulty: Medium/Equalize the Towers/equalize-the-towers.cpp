class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        vector<pair<int,int>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }

        // Sort towers by height
        sort(towers.begin(), towers.end());

        long long totalWeight = 0;
        for(auto &t : towers) {
            totalWeight += t.second;
        }

        // Find weighted median
        long long currWeight = 0;
        int targetHeight = 0;

        for(auto &t : towers) {
            currWeight += t.second;
            if(currWeight >= (totalWeight + 1) / 2) {
                targetHeight = t.first;
                break;
            }
        }

        // Calculate minimum cost
        long long ans = 0;
        for(auto &t : towers) {
            ans += 1LL * abs(t.first - targetHeight) * t.second;
        }

        return ans;
    }
};
