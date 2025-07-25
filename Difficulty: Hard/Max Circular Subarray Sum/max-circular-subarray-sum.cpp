class Solution {
  public:
  
  int kadaneMax(const vector<int>& arr) {
    int maxEndingHere = arr[0], maxSoFar = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
  }

 int kadaneMin(const vector<int>& arr) {
    int minEndingHere = arr[0], minSoFar = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        minEndingHere = min(arr[i], minEndingHere + arr[i]);
        minSoFar = min(minSoFar, minEndingHere);
    }
    return minSoFar;
 }
 
 int maxCircularSum(vector<int> &arr) {
        int maxNormal = kadaneMax(arr);
    int totalSum = 0;
    for (int num : arr) totalSum += num;

    int minSubarraySum = kadaneMin(arr);
    int maxCircular = totalSum - minSubarraySum;

    // If all numbers are negative, maxCircular becomes 0 (invalid), so return maxNormal
    if (maxNormal < 0) return maxNormal;

    return max(maxNormal, maxCircular);
    }
};