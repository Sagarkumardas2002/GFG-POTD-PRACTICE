class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int maxOnes = 0;
        int answerRow = -1;
        
        for(int i = 0; i < n; i++) {
            int countOnes = 0;
            
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1)
                    countOnes++;
            }
            
            if(countOnes > maxOnes) {
                maxOnes = countOnes;
                answerRow = i;
            }
        }
        
        return answerRow;
    }
};
