class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        vector<int> pos(n + 1);

        // Store position of every value
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        int longest = 1;
        int current = 1;

        // Check consecutive values: x, x+1, x+2...
        for (int x = 1; x < n; x++) {
            if (pos[x] < pos[x + 1]) {
                current++;
            } else {
                current = 1;
            }

            longest = max(longest, current);
        }

        return n - longest;
    }
};