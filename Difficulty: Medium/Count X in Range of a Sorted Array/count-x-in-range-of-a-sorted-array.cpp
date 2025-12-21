class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            
            auto left = lower_bound(arr.begin() + l, arr.begin() + r + 1, x);
            auto right = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);
            
            result.push_back(right - left);
        }
        
        return result;
    }
};
