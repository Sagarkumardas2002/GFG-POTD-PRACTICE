class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        
        int maxEnding = arr[0], maxSoFar = arr[0];
        int minEnding = arr[0], minSoFar = arr[0];
        
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
            
            if (i > 0) {
                maxEnding = max(arr[i], maxEnding + arr[i]);
                maxSoFar = max(maxSoFar, maxEnding);
                
                minEnding = min(arr[i], minEnding + arr[i]);
                minSoFar = min(minSoFar, minEnding);
            }
        }
        
        // If all elements are negative
        if (maxSoFar < 0)
            return maxSoFar;
        
        return max(maxSoFar, totalSum - minSoFar);
    }
};
