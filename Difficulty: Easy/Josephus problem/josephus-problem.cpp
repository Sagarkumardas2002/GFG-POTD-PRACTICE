class Solution {
  public:
    int josephus(int n, int k) {
        int ans = 0;   // J(1, k) = 0 (0-based)

        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }

        return ans + 1; // convert to 1-based index
    }
};
