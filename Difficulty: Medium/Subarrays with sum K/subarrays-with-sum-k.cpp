class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
         unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // base case for exact sum = k
        int currSum = 0, count = 0;

        for (int num : arr) {
            currSum += num;

            if (prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currSum - k];
            }

            prefixSumCount[currSum]++;
        }

        return count;
    }
};