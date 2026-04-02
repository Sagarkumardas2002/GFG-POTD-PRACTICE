class Solution {
public:
    int countWays(int n, int k) {
        
        if(n == 1) return k;
        
        // For n = 2
        int same = k;              // same color (RR, BB...)
        int diff = k * (k - 1);    // different color
        
        for(int i = 3; i <= n; i++) {
            int newSame = diff;   // only way to get same
            int newDiff = (same + diff) * (k - 1);
            
            same = newSame;
            diff = newDiff;
        }
        
        return same + diff;
    }
};