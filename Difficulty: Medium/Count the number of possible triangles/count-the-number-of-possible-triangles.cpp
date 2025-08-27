class Solution {
  public:
    int countTriangles(vector<int>& arr) {
    int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;
    
        for (int k = n - 1; k >= 2; k--) {
            int left = 0, right = k - 1;
            while (left < right) {
                if (arr[left] + arr[right] > arr[k]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};
