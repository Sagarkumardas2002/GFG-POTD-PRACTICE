class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        
        // Step 2: Add first interval
        result.push_back(arr[0]);
        
        // Step 3: Merge overlapping intervals
        for(int i = 1; i < arr.size(); i++) {
            // If overlapping
            if(arr[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], arr[i][1]);
            } 
            // If not overlapping
            else {
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};
