class Solution {
  public:
    string largestSwap(string s) {
        int n = s.size();
        vector<int> maxRight(n);

        // maxRight[i] stores the index of the rightmost largest digit from i..n-1
        maxRight[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int rightMaxInd = maxRight[i + 1];
            char rightMaxElement = s[rightMaxInd];
            // strictly '>' so that we keep the rightmost max
            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxInd;
        }

        // find the first place where a swap can make string larger
        for (int i = 0; i < n; i++) {
            int maxRightIndex = maxRight[i];
            if (s[i] < s[maxRightIndex]) {
                swap(s[i], s[maxRightIndex]);
                return s;  // return immediately after swap
            }
        }

        return s; // if no swap improves result
    }
};
