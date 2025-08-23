class Solution {
  public:
    // Check if allocation with given maxPages is possible
    bool isAllocationPossible(vector<int> &arr, int n, int k, int maxPages) {
        int studentCount = 1, pageSum = 0;

        for (int i = 0; i < n; i++) {
            if (pageSum + arr[i] <= maxPages) {
                pageSum += arr[i];  // add book to current student
            } else {
                studentCount++;     // allocate to next student
                if (studentCount > k || arr[i] > maxPages) return false;
                pageSum = arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;  // impossible if students > books

        int start = 0, totalPages = 0;
        for (int i = 0; i < n; i++) totalPages += arr[i];

        int end = totalPages;  
        int answer = -1;   // ✅ only one declaration

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isAllocationPossible(arr, n, k, mid)) {
                answer = mid;
                end = mid - 1;   // try smaller maximum
            } else {
                start = mid + 1; // need bigger maximum
            }
        }
        return answer;
    }
};
