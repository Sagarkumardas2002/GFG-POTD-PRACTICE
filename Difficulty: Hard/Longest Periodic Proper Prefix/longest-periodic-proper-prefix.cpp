class Solution {
  public:
    int getLongestPrefix(string &s) {
         int n = s.length();
        if (n < 2) return -1;

        const long long mod1 = 1000000007LL;
        const long long mod2 = 1000000009LL;
        const long long base1 = 131LL;
        const long long base2 = 137LL;

        vector<long long> pow1(n + 1), pow2(n + 1);
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] * base1) % mod1;
            pow2[i] = (pow2[i - 1] * base2) % mod2;
        }

        vector<long long> hash1(n + 1), hash2(n + 1);
        for (int i = 0; i < n; i++) {
            long long charCode = (long long)s[i];
            hash1[i + 1] = (hash1[i] * base1 + charCode) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + charCode) % mod2;
        }

        for (int k = n - 1; k >= 1; k--) {
            int len = n - k;
            long long hA1 = hash1[len];
            long long hA2 = hash2[len];

            long long hB1 = (hash1[k + len] - (hash1[k] * pow1[len]) % mod1 + mod1) % mod1;
            long long hB2 = (hash2[k + len] - (hash2[k] * pow2[len]) % mod2 + mod2) % mod2;

            if (hA1 == hB1 && hA2 == hB2) return k;
        }

        return -1;
    }
};