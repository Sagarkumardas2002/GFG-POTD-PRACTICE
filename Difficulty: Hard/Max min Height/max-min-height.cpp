class Solution {
  public:
  bool isPossible(vector<int> &arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> diff(n + 1, 0);
        int ops = 0, currAdd = 0;

        for (int i = 0; i < n; ++i) {
            currAdd += diff[i];
            int height = arr[i] + currAdd;
            if (height < target) {
                int need = target - height;
                ops += need;
                if (ops > k) return false;
                currAdd += need;
                if (i + w < n) diff[i + w] -= need;
            }
        }
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
       int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = low;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};