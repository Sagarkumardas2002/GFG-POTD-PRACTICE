class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
       int n = arr.size();
        int needed = (n + 1) / 2; // ceil(n/2)
        int luckyCount = 0;
        vector<int> cost;

        for (int soldiers : arr) {
            if (soldiers % k == 0) {
                luckyCount++;
            } else {
                cost.push_back(k - soldiers % k);
            }
        }

        if (luckyCount >= needed) return 0;

        sort(cost.begin(), cost.end());
        int totalAdd = 0;
        for (int i = 0; i < needed - luckyCount; i++) {
            totalAdd += cost[i];
        }

        return totalAdd;
        
    }
};