class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int j = 0;
        int ans = 0;

        for (int i = 0; i < mid; i++) {
            while (j < mid && (long long)left[i] >= 5LL * right[j]) {
                j++;
            }

            ans += j;
        }

        return ans;
    }
};