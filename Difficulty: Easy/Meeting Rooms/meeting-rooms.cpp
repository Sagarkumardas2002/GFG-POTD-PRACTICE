class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Sort meetings based on start time
        sort(arr.begin(), arr.end());
        
        // Check for overlap
        for(int i = 1; i < arr.size(); i++) {
            // If current meeting starts before previous ends → overlap
            if(arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        
        return true; // No overlaps found
    }
};
