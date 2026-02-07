class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        
        int arraySum = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            arraySum += arr[i];
            curr += i * arr[i];
        }
        
        int ans = curr;
        for (int i = 1; i < n; i++) {
            curr = curr + arraySum - n * arr[n - i];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
