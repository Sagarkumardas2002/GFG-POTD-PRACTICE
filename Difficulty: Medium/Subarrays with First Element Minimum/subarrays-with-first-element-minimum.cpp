class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;
        vector<int> nextSmaller(n, n);
        
        // Find next smaller element index
        for(int i = n - 1; i >= 0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            
            st.push(i);
        }
        
        int totalSubarrays = 0;
        
        for(int i = 0; i < n; i++){
            totalSubarrays += nextSmaller[i] - i;
        }
        
        return totalSubarrays;
    }
};