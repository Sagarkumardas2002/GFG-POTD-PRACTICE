class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);

        // Step 1: Initialize dp with arr values
        for(int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        // Step 2: Build dp
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        // Step 3: Return max from dp
        int answer = 0;
        for(int val : dp) {
            answer = max(answer, val);
        }
        return answer;
    }
};
