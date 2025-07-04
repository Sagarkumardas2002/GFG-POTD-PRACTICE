class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n=arr.size();
        int left=0;
        int totalSubarray=0;
        
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            mp[arr[right]]++;
            if(mp[arr[right]]==1) {
                k--;
            }
            
            while(k<0){
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    k++;
                }
                left++;
            }
            totalSubarray+=right-left+1;
        }
        return totalSubarray;
    }
}; 