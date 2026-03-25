// User function Template for C++

class Solution {
  public:
    void Addition(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
       int n=matrixA.size();
       int m=matrixA[0].size();
       
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               matrixA[i][j]=matrixA[i][j]+matrixB[i][j];
           }
       }
        
    }
};