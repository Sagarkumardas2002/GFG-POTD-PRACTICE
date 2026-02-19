class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        
        // store array elements for fast checking
        unordered_set<int> present(arr.begin(), arr.end());
        
        vector<int> result;
        
        // check all numbers in range [low, high]
        for(int num = low; num <= high; num++){
            if(present.find(num) == present.end()){
                result.push_back(num); // missing number
            }
        }
        
        return result;
    }
};
