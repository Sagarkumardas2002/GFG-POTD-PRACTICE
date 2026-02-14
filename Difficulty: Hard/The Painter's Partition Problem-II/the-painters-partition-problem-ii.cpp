class Solution {
  public:

    // check if we can paint within maxTime using <= k painters
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long currentTime = 0;
        int painters = 1;

        for(int length : arr) {
            // single board itself larger than allowed time
            if(length > maxTime) return false;

            if(currentTime + length <= maxTime) {
                currentTime += length;
            } else {
                painters++;          // need new painter
                currentTime = length;

                if(painters > k) return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end()); // min possible
        long long high = 0;

        for(int x : arr) high += x;  // max possible

        long long ans = high;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller time
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
