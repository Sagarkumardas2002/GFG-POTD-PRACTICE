class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        // edge cases
        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int requiredSum = (target + totalSum) / 2;

        // DP array
        vector<int> dp(requiredSum + 1, 0);
        dp[0] = 1;  // one way to get sum 0

        for (int num : arr) {
            for (int j = requiredSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[requiredSum];
    }
};