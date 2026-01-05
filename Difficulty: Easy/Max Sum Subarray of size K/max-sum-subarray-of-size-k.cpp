class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int windowSum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];        // add next element
            windowSum -= arr[i - k];    // remove previous element
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};
