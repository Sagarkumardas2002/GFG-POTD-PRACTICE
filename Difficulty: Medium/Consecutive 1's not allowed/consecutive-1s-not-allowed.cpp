class Solution {
  public:
    int countStrings(int n) {
        // Base case
        int endingWith0 = 1; // for length 1 -> "0"
        int endingWith1 = 1; // for length 1 -> "1"
        
        for(int i = 2; i <= n; i++) {
            int newEndingWith0 = endingWith0 + endingWith1;
            int newEndingWith1 = endingWith0;
            
            endingWith0 = newEndingWith0;
            endingWith1 = newEndingWith1;
        }
        
        return endingWith0 + endingWith1;
    }
};