class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int left = max(0, i - arr[i]);
                int right = min(n - 1, i + arr[i]);
                intervals.push_back({left, right});
            }
        }

        // Sort intervals by start, and by end descending if start is same
        sort(intervals.begin(), intervals.end());

        int workers = 0;
        int current = 0;
        int i = 0;

        // Step 2: Greedy interval covering
        while (current < n) {
            int farthest = -1;

            // Extend coverage as far as possible
            while (i < intervals.size() && intervals[i].first <= current) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }

            // No interval can cover current position
            if (farthest < current) {
                return -1;
            }

            workers++;
            current = farthest + 1;
        }

        return workers;
    }
};
