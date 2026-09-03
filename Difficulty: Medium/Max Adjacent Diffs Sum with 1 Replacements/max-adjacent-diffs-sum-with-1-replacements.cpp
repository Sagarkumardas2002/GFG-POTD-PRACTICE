class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        long long keep = 0, repl = 0; // dp values for index 0

        for (int i = 1; i < n; i++) {
            long long newKeep = max(keep + abs(arr[i] - arr[i-1]),
                                     repl + abs(arr[i] - 1));
            long long newRepl = max(keep + abs(1 - arr[i-1]),
                                     repl + 0);
            keep = newKeep;
            repl = newRepl;
        }

        return (int)max(keep, repl);
    }
};