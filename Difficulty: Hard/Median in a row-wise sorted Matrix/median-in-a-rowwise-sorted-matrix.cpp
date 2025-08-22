class Solution {
  public:
    int median(vector<vector<int>> &mat) {
       int n=mat.size();
       int m=mat[0].size();
       
             int low = INT_MAX, high = INT_MIN;
        
        // Find min and max in matrix
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);       // first element of row
            high = max(high, mat[i][m-1]);   // last element of row
        }

        int desired = (n * m + 1) / 2; // median position

        while (low < high) {
            int mid = low + (high - low) / 2;

            // count numbers <= mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count < desired)
                low = mid + 1;  // median is larger
            else
                high = mid;     // median is smaller or equal
        }

        return low; // or high, both same
    }
};
