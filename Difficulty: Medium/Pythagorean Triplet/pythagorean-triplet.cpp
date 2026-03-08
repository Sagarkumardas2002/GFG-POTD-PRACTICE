class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        
        int n = arr.size();
        
        unordered_set<int> st;
        
        // store squares
        for(int i = 0; i < n; i++){
            st.insert(arr[i] * arr[i]);
        }
        
        // check pairs
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                
                if(st.find(sum) != st.end()){
                    return true;
                }
            }
        }
        
        return false;
    }
};