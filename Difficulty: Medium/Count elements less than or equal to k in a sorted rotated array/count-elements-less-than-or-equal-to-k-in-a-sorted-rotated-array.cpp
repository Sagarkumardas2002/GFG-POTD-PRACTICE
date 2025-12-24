class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        
        // Step 1: Find pivot (index of minimum element)
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        // Step 2: Count elements <= x in both sorted parts
        int count = 0;
        count += upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);
        count += upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();

        return count;
    }
};
