class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
       
       int n=arr.size();
       sort(arr.rbegin(),arr.rend());

       int largest=arr[0];
       int secondLargest=-1;
       
       
       
       for(int i=1;i<n;i++){
           if(largest!=arr[i]){
               secondLargest=arr[i];
               break;
           }
       }
       
       if(secondLargest==-1) return -1;
       
       return secondLargest;
    
    }
};