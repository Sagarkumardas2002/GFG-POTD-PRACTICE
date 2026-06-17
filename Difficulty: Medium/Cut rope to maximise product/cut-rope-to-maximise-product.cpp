class Solution {
  public:
    int maxProduct(int n) {
        
        // Base cases: formula doesn't apply here
        if (n == 2) return 1;   // must cut → 1×1
        if (n == 3) return 2;   // must cut → 1×2
        
        if (n % 3 == 0)
            return pow(3, n/3);          // all 3s
        
        else if (n % 3 == 2)
            return 2 * pow(3, (n-2)/3);  // one 2, rest 3s
        
        else // n % 3 == 1
            return 4 * pow(3, (n-4)/3);  // one 4(=2×2), rest 3s
    }
};