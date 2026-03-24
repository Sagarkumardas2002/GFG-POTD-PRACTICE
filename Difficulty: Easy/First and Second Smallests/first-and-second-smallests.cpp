class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
       
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int first=arr[0];
        int second = -1;
        
        for(int i=1;i<n;i++){
            if(arr[i]!=first){
                second=arr[i];
                break;
            }
        }
        
        if(second==-1) return {-1};
        return {first,second};
    }
};