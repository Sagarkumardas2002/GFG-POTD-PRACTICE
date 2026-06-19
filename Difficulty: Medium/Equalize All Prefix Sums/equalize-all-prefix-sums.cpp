class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();

        vector<long long> prefix(n);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int mid = i / 2;
            long long median = arr[mid];

            long long leftCost = median * mid;
            if (mid > 0) {
                leftCost -= prefix[mid - 1];
            }

            long long rightCost =
                (prefix[i] - prefix[mid]) -
                median * (i - mid);

            ans[i] = leftCost + rightCost;
        }

        return ans;
    }
};