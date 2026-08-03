class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        // Kadane: maximum sum subarray ending at each index
        vector<int> maxEndingHere(n);
        maxEndingHere[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxEndingHere[i] = max(arr[i], maxEndingHere[i - 1] + arr[i]);
        }

        // Sum of first k elements
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];

            // Window of exactly k
            ans = max(ans, windowSum);

            // Extend with previous positive Kadane sum
            ans = max(ans, windowSum + maxEndingHere[i - k]);
        }

        return ans;
    }
};