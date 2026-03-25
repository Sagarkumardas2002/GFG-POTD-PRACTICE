class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i]){
                return false;
                break;
            }
        }
        return true;
    }
};