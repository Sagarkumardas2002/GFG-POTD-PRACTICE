class Solution {
  public:
    int findMean(vector<int>& arr) {
        int n=arr.size();
        int totalSum=0;
        for(int it:arr){
            totalSum+=it;
        }
        int mean=totalSum/n;
        return mean;
        
    }
};