class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int maxWater = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            int water = width * height;

            // take the maximum area found so far
            maxWater = max(maxWater, water);

            // move the pointer pointing to the shorter line
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};