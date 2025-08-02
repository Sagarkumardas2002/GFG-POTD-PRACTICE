class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixIndex;
        int maxLen = 0, sum = 0;
    
        for (int i = 0; i < n; ++i) {
            // Convert element to +1 or -1
            sum += (arr[i] > k) ? 1 : -1;
    
            if (sum > 0) {
                maxLen = i + 1;
            } else {
                if (prefixIndex.find(sum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[sum - 1]);
                }
            }
    
            // Store first occurrence of prefix sum
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }
    return maxLen;
    }
};