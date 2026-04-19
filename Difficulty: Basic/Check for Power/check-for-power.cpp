class Solution {
  public:
    bool isPower(int x, int y) {
       // Special case
        if (x == 1) return (y == 1);

        // Keep dividing y by x
        while (y % x == 0) {
            y = y / x;
        }

        // If we reach 1, it's a power
        return (y == 1);
    }
};