class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0;
        int j = m - 1;
        
        int minDiff = INT_MAX;
        int first = 0, second = 0;
        
        while(i < n && j >= 0) {
            
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);
            
            // Update best pair
            if(diff < minDiff) {
                minDiff = diff;
                first = arr1[i];
                second = arr2[j];
            }
            
            // Move pointers
            if(sum > x) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return {first, second};
    }
};