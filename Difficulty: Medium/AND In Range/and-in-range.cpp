class Solution {
public:
    int andInRange(int l, int r) {
        int shift = 0;

        // keep shifting until both numbers become equal
        while (l != r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }

        // shift back to get the common prefix
        return l << shift;
    }
};
