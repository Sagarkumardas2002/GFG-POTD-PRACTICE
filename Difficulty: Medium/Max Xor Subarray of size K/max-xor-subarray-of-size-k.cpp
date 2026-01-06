class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
       int n = arr.size();
        int xorResult = 0;
        int result = 0;

        // XOR of first window
        for(int i = 0; i < k; i++) {
            xorResult ^= arr[i];
        }
        result = xorResult;

        // Slide the window
        for(int i = k; i < n; i++) {
            xorResult ^= arr[i - k];  // remove left element
            xorResult ^= arr[i];       // add right element
            result = max(result, xorResult);
        }

        return result;
    }
};