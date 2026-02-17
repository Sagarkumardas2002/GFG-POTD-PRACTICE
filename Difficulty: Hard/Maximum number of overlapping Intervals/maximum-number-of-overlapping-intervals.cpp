class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {

        int n = arr.size();

        vector<int> start(n);
        vector<int> end(n);

        // Store start and end times separately
        for (int i = 0; i < n; i++) {
            start[i] = arr[i][0];
            end[i] = arr[i][1];
        }

        // Sort both arrays
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0;  // pointer for start
        int j = 0;  // pointer for end
        int currentOverlap = 0;
        int maxOverlap = 0;

        // Traverse both arrays
        while (i < n && j < n) {

            // If next event is start (inclusive interval)
            if (start[i] <= end[j]) {
                currentOverlap++;
                maxOverlap = max(maxOverlap, currentOverlap);
                i++;
            }
            else {
                currentOverlap--;
                j++;
            }
        }

        return maxOverlap;
    }
};
