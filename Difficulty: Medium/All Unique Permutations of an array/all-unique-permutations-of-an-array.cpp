class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(arr.size(), false);
        
        sort(arr.begin(), arr.end()); // Sort for lexicographic order
        backtrack(arr, used, current, result);
        
        return result;
    }
    
  private:
    void backtrack(vector<int>& arr, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == arr.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue; 
            
            // Skip duplicates (only use first unused duplicate)
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;
            
            used[i] = true;
            current.push_back(arr[i]);
            
            backtrack(arr, used, current, result);
            
            current.pop_back();
            used[i] = false;
        }
    }
};
