class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
      
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int n=mices.size();
        int maxValue=0;
        
        for(int i=0;i<n;i++){
            maxValue=max(maxValue,abs(mices[i]-holes[i]));
        }
        return maxValue;
    }
};