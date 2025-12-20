class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == k) {
                return mid;          // element found
            } 
            else if (arr[mid] < k) {
                low = mid + 1;       // move right
            } 
            else {
                high = mid - 1;      // move left
            }
        }
        
        // k not found → low is the correct insert position
        return low;
    }
};
