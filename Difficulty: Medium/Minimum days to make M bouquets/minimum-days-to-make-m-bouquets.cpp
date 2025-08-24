#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if(1LL * m * k > n) return -1;  // not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        auto canMake = [&](int day) {
            int bouquets = 0, consecutive = 0;
            for(int bloom : arr) {
                if(bloom <= day) {
                    consecutive++;
                    if(consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                } else {
                    consecutive = 0;
                }
            }
            return bouquets >= m;
        };

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canMake(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
