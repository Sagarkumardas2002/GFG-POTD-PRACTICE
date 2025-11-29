class Solution {
  public:
    int countSetBits(int n) {
       long long total = 0;
        
        for (long long i = 0; (1LL << i) <= n; i++) {
            long long cycle = 1LL << (i + 1);
            long long fullCycles = n / cycle;
            long long onesInFull = fullCycles * (1LL << i);
            
            long long rem = n % cycle;
            long long onesInRem = max(0LL, rem - (1LL << i) + 1);
            
            total += onesInFull + onesInRem;
        }
        return total;
        
    }
};
