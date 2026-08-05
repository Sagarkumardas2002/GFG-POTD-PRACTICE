class Solution {
public:

    long long countAtMost(vector<int>& arr, int k) {

        if (k < 0)
            return 0;

        long long count = 0;
        long long currentSum = 0;

        int left = 0;

        for (int right = 0; right < arr.size(); right++) {

            currentSum += arr[right];

            while (currentSum > k) {
                currentSum -= arr[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int countSubarray(vector<int>& arr, int l, int r) {

        return countAtMost(arr, r) - countAtMost(arr, l - 1);
    }
};