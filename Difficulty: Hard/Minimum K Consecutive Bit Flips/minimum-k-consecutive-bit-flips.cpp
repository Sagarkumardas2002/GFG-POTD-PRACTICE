class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);  // marks where flips start
        int flips = 0;                // count of total flips
        int flipped = 0;              // current flip parity (0 = even, 1 = odd)

        for (int i = 0; i < n; i++) {
            // Remove effect of flip that has gone out of the window
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
    
            // If current bit (after flips) is 0, we must flip here
            if ((arr[i] ^ flipped) == 0) {
                if (i + k > n) return -1;  // not enough space to flip
                flips++;
                flipped ^= 1;              // toggle flip state
                isFlipped[i] = 1;          // mark flip start
            }
        }

        return flips; 
        
    }
};