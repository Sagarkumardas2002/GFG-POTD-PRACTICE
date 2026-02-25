class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        
        unordered_map<int, int> firstIndex; 
        int prefix = 0;
        int maxLength = 0;
        
        for(int i = 0; i < n; i++) {
            
            // Convert to +1 / -1
            if(arr[i] > k)
                prefix += 1;
            else
                prefix -= 1;
            
            // Case 1: whole subarray from 0 to i is valid
            if(prefix > 0) {
                maxLength = i + 1;
            }
            
            // Store first occurrence of prefix
            if(firstIndex.find(prefix) == firstIndex.end()) {
                firstIndex[prefix] = i;
            }
            
            // Case 2: check if prefix-1 existed
            if(firstIndex.find(prefix - 1) != firstIndex.end()) {
                int length = i - firstIndex[prefix - 1];
                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength;
    }
};