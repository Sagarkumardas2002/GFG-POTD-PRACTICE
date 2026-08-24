class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int prefixStrings(int n) {
        long long catalan = 1;

        for (long long i = 1; i <= n; i++) {
            catalan = catalan * (2 * (2 * i - 1)) % MOD;
            catalan = catalan * power(i + 1, MOD - 2) % MOD;
        }

        return catalan;
    }
};