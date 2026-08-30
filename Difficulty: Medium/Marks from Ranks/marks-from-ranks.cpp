class Solution {
    public:
      vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
          int n = l.size();

          // prefix[i] = number of valid marks up to interval i
          vector<long long> prefix(n);

          for (int i = 0; i < n; i++) {
              long long cnt = r[i] - l[i] + 1;
              prefix[i] = cnt + (i > 0 ? prefix[i - 1] : 0);
          }

          vector<int> ans;

          for (int k : rank) {
              // Find first interval whose prefix >= k
              int i = lower_bound(prefix.begin(), prefix.end(), k) 
                      - prefix.begin();

              // Number of marks before this interval
              long long before = (i > 0 ? prefix[i - 1] : 0);

              // Position inside the interval (0-based)
              long long pos = k - before - 1;

              // Corresponding mark
              ans.push_back(l[i] + pos);
          }

          return ans;
      }
  };