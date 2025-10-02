class Solution {
  public:
    vector<vector<int>> combinationSum(int n, int k) {
       vector<vector<int>> result;
        vector<int> path;
        backtrack(1, k, n, path, result);
        return result;
    }

    void backtrack(int start, int k, int n, vector<int>& path, vector<vector<int>>& result) {
        // if path has k numbers
        if (path.size() == k) {
            if (n == 0) result.push_back(path); // valid combination
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; // pruning (no need to continue if sum exceeds n)

            path.push_back(i);
            backtrack(i + 1, k, n - i, path, result); // move to next number
            path.pop_back(); // backtrack
        }
    }
};