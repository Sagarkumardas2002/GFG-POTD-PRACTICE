class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        
        // edge case
        if(m == 0 || n == 0) return 0;
        if(m > n) return -1;
        
        // step 1: sort packets
        sort(a.begin(), a.end());
        
        // step 2: check all windows of size m
        int minDiff = INT_MAX;
        
        for(int i = 0; i <= n - m; i++){
            int diff = a[i + m - 1] - a[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};
