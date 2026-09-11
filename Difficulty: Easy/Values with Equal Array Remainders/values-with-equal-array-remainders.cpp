class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        int g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[i - 1]));
        }

        // All elements are equal
        if (g == 0) {
            return -1;
        }

        // Count divisors of g
        int count = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;

                if (i != g / i) {
                    count++;
                }
            }
        }

        return count;
    }
};