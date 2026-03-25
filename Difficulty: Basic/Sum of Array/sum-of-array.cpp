// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
       int sum=0;
       for(auto it:arr){
           sum+=it;
       }
        return sum;
    }
};