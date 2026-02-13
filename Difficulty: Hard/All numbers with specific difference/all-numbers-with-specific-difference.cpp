class Solution {
  public:
    
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    int getCount(int n, int d) {
        int count = 0;
        
        // Upper safe limit where condition is always true
        int startAlwaysTrue = d + 90;
        
        // Count numbers where condition always holds
        if (startAlwaysTrue <= n) {
            count += (n - startAlwaysTrue + 1);
        }
        
        // Check boundary range manually
        for (int x = d; x <= n && x < startAlwaysTrue; x++) {
            if (x - digitSum(x) >= d) {
                count++;
            }
        }
        
        return count;
    }
};
