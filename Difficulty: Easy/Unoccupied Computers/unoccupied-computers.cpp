class Solution {
  public:
    int solve(int n, string s) {
        vector<int> status(26, 0);
        int occupied = 0;
        int rejected = 0;

        for (char c : s) {
            int x = c - 'A';

            // First occurrence
            if (status[x] == 0) {
                if (occupied < n) {
                    status[x] = 1;   // got a computer
                    occupied++;
                } else {
                    status[x] = 2;   // rejected
                    rejected++;
                }
            }
            // Second occurrence
            else if (status[x] == 1) {
                // Customer had a computer, so free it
                status[x] = 0;
                occupied--;
            }
            else {
                // status == 2
                // Customer was rejected, so nothing to free
                status[x] = 0;
            }
        }

        return rejected;
    }
};