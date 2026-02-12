class Solution {
public:

    // Check if we can make all heights >= target
    bool canAchieve(vector<int>& arr, int k, int w, long long target) {
        int n = arr.size();
        vector<long long> extra(n, 0); // difference array
        long long usedDays = 0;
        long long currentWater = 0;

        for(int i = 0; i < n; i++) {
            currentWater += extra[i];

            long long currentHeight = arr[i] + currentWater;

            // if height still less than target
            if(currentHeight < target) {
                long long need = target - currentHeight;
                usedDays += need;

                if(usedDays > k) return false;

                currentWater += need;

                // remove effect after range w
                if(i + w < n)
                    extra[i + w] -= need;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();

        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = low;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1; // try bigger minimum
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
