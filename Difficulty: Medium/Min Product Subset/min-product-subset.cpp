class Solution {
  public:
    int minProd(vector<int>& arr) {
        int negCount = 0;
        int zeroCount = 0;
        int largestNeg = -11;   // largest negative number
        int product = 1;

        for (int x : arr) {
            if (x < 0) {
                negCount++;
                largestNeg = max(largestNeg, x);
                product *= x;
            }
            else if (x == 0) {
                zeroCount++;
            }
            else {
                product *= x;
            }
        }

        // No negative numbers
        if (negCount == 0) {
            if (zeroCount > 0)
                return 0;

            int ans = INT_MAX;
            for (int x : arr)
                ans = min(ans, x);

            return ans;
        }

        // Even number of negative numbers
        // Remove the negative number closest to zero
        if (negCount % 2 == 0) {
            product /= largestNeg;
        }

        return product;
    }
};