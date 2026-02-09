class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum lies in right half
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }

        // low is the index of minimum element
        return low;
    }
};
