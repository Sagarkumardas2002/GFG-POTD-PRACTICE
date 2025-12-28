class Solution {
public:
    bool canMake(int time, vector<int>& ranks, int n) {
        int donuts = 0;

        for (int r : ranks) {
            int currTime = 0;
            int k = 1;

            while (true) {
                currTime += r * k;
                if (currTime > time) break;
                donuts++;
                k++;
            }

            if (donuts >= n) return true;
        }

        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int low = 0;
        int high = *max_element(ranks.begin(), ranks.end()) * n * (n + 1) / 2;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid, ranks, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
