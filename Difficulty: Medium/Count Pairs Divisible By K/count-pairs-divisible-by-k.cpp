class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : arr) {
            int rem = x % k;
            int need = (k - rem) % k;

            ans += mp[need];
            mp[rem]++;
        }

        return ans;
    }
};