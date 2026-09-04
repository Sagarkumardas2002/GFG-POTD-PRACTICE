class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        long long windowSum = 0;
        long long ans = 0;

        // First window
        for (int i = 0; i < m; i++) {
            windowSum += arr[i];
        }

        ans = windowSum;

        // Slide over circular array
        for (int i = m; i < n + m - 1; i++) {
            windowSum += arr[i % n];
            windowSum -= arr[(i - m) % n];

            ans = max(ans, windowSum);
        }

        return (int)ans;
    }
};