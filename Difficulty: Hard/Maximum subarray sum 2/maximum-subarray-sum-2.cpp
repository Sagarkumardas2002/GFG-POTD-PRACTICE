class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
         int n = arr.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + arr[i];
    
        long long ans = LLONG_MIN;
        deque<int> dq; // stores indices of prefix sums
    
        for (int r = a; r <= n; r++) {
            // insert valid left boundary index (r-a)
            int leftIdx = r - a;
            while (!dq.empty() && prefix[dq.back()] >= prefix[leftIdx])
                dq.pop_back();
            dq.push_back(leftIdx);
    
            // remove out-of-window indices (r-b)
            int outIdx = r - b - 1;
            if (!dq.empty() && dq.front() == outIdx)
                dq.pop_front();
    
            // best sum ending at r
            ans = max(ans, prefix[r] - prefix[dq.front()]);
        }
        return ans;
        
    }
};