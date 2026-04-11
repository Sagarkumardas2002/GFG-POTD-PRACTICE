class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int len = 1;   // current increasing segment length
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                len++;  // extend segment
            } else {
                count += (len * (len - 1)) / 2;
                len = 1; // reset
            }
        }

        // add last segment
        count += (len * (len - 1)) / 2;

        return count;
    }
};