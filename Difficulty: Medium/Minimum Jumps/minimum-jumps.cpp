class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // If array has only one element → no jump needed
        if (n <= 1) return 0;
        
        // If first element is 0 → can't move
        if (arr[0] == 0) return -1;
        
        // Initialize
        int maxReach = arr[0];   // farthest index we can reach
        int steps = arr[0];      // steps left in current jump
        int jumps = 1;           // we need at least one jump
        
        for (int i = 1; i < n; i++) {
            // Reached the end
            if (i == n - 1) return jumps;
            
            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);
            
            // Use one step
            steps--;
            
            // If no steps left → must jump
            if (steps == 0) {
                jumps++;
                
                // If we are stuck
                if (i >= maxReach) return -1;
                
                // Reinitialize steps for the new jump
                steps = maxReach - i;
            }
        }
        
        return -1; // If end is not reachable
    }
};
