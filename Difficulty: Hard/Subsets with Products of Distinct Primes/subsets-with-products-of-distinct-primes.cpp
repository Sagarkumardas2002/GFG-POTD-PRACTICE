class Solution {
public:
    const int MOD = 1e9 + 7;

    int countSubsets(vector<int> &arr) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        int ones = 0;

        for (int num : arr) {

            if (num == 1) {
                ones++;
                continue;
            }

            int x = num;
            int mask = 0;
            bool valid = true;

            for (int i = 0; i < 10; i++) {
                int prime = primes[i];

                int count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    count++;
                }

                if (count > 1) {
                    valid = false;
                    break;
                }

                if (count == 1) {
                    mask |= (1 << i);
                }
            }

            if (!valid)
                continue;

            for (int oldMask = (1 << 10) - 1; oldMask >= 0; oldMask--) {
                if ((oldMask & mask) == 0) {
                    dp[oldMask | mask] =
                        (dp[oldMask | mask] + dp[oldMask]) % MOD;
                }
            }
        }

        long long answer = 0;

        for (int mask = 1; mask < (1 << 10); mask++) {
            answer = (answer + dp[mask]) % MOD;
        }

        long long power = 1;
        long long base = 2;

        while (ones) {
            if (ones & 1)
                power = (power * base) % MOD;

            base = (base * base) % MOD;
            ones >>= 1;
        }

        answer = (answer * power) % MOD;

        return answer;
    }
};