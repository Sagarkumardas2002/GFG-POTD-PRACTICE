class Solution {
  public:
    int missingNum(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // sort the array
        int n = arr.size() + 1;        // total numbers
    
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != i + 1) {
                return i + 1;          // missing number found
            }
        }
        return n;   
    }
};