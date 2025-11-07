class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // Step 1: Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int n = jobs.size();
        vector<int> dp(n);  // dp[i] = max profit till i-th job

        dp[0] = jobs[0][2]; // Base case: profit of first job

        for (int i = 1; i < n; i++) {
            // Include current job's profit
            int includeProfit = jobs[i][2];

            // Step 2: Find last non-overlapping job using binary search
            int l = 0, r = i - 1, lastNonOverlap = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    lastNonOverlap = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // Add profit of last non-overlapping job (if exists)
            if (lastNonOverlap != -1)
                includeProfit += dp[lastNonOverlap];

            // Step 3: Take maximum of including or excluding current job
            dp[i] = max(dp[i - 1], includeProfit);
        }

        // Step 4: The last element in dp has the answer
        return dp[n - 1];
    }
};