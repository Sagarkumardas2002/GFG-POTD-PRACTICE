class Solution {
public:
    // merge function to count cross inversions
    long long merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        long long invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } 
            else {
                temp.push_back(arr[j]);
                invCount += (mid - i + 1); // all remaining left elements form inversion
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // copy back to original array
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return invCount;
    }

    long long mergeSort(vector<int> &arr, int left, int right) {
        long long invCount = 0;
        
        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSort(arr, left, mid);
            invCount += mergeSort(arr, mid + 1, right);
            invCount += merge(arr, left, mid, right);
        }

        return invCount;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
