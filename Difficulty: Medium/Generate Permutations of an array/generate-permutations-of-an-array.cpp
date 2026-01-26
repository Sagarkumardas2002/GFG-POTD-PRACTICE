class Solution {
  public:
    void solve(int index, vector<int>& arr, vector<vector<int>>& result) {
        // Base case: one permutation formed
        if (index == arr.size()) {
            result.push_back(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);      // choose
            solve(index + 1, arr, result); // explore
            swap(arr[index], arr[i]);      // un-choose (backtrack)
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        solve(0, arr, result);
        return result;
    }
};
