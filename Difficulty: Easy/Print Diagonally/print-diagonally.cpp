class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> result;

        // Step 1: Start from top row
        for(int col = 0; col < n; col++) {
            int i = 0, j = col;
            
            while(i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        // Step 2: Start from last column
        for(int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            
            while(i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return result;
    }
};