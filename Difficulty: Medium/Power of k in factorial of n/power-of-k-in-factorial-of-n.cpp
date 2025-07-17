class Solution {
  public:
  
      int countInFactorial(int n, int p) {
        int count = 0;
        for (long long power = p; power <= n; power *= p)
            count += n / power;
        return count;
    }


    int maxKPower(int n, int k) {
        int ans = INT32_MAX;
        int originalK = k;

        // Prime factorize k
        for (int i = 2; i * i <= k; ++i) {
            if (k % i == 0) {
                int countInK = 0;
                while (k % i == 0) {
                    countInK++;
                    k /= i;
                }
                int countInFact = countInFactorial(n, i);
                ans = min(ans, countInFact / countInK);
            }
        }

        // If any prime factor > sqrt(k) remains
        if (k > 1) {
            int countInFact = countInFactorial(n, k);
            ans = min(ans, countInFact); // since exponent in k is 1
        }

        return ans;
    }
};