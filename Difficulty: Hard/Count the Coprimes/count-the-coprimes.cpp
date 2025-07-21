class Solution {
  public:
  int cntCoprime(vector<int>& arr) {
     int n = arr.size();
        int maxVal = *max_element(arr.begin(), arr.end());

        // Frequency of each number
        vector<int> freq(maxVal + 1, 0);
        for (int x : arr) freq[x]++;

        // Count of elements divisible by each i
        vector<int> countDiv(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            for (int j = i; j <= maxVal; j += i) {
                countDiv[i] += freq[j];
            }
        }

        // Inclusion-Exclusion to count pairs with GCD = d
        vector<long long> dp(maxVal + 1, 0);
        for (int i = maxVal; i >= 1; i--) {
            long long c = countDiv[i];
            dp[i] = c * (c - 1) / 2;
            for (int j = 2 * i; j <= maxVal; j += i) {
                dp[i] -= dp[j];
            }
        }

        long long totalPairs = 1LL * n * (n - 1) / 2;
        long long coprimePairs = dp[1];
        return (int)coprimePairs;
  }
};
