    class Solution {
      public:
        int countNumbers(int n) {
             vector<int> primes;
        int limit = sqrt(n) + 1;

        // Sieve of Eratosthenes to generate primes
        vector<bool> isPrime(limit + 1, true);
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }

        int count = 0;

        // Case 1: p^8
        for (int p : primes) {
            long long val = 1;
            for (int i = 0; i < 8; i++) val *= p;
            if (val <= n) count++;
            else break;
        }

        // Case 2: p^2 * q^2
        int len = primes.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n) count++;
                else break;
            }
        }

        return count;
            
        }
    };