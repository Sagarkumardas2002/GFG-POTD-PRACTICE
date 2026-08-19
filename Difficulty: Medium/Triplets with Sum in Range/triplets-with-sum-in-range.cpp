class Solution {
public:

    long long countLessEqual(vector<int>& arr, int X) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = 1LL * arr[i] + arr[j] + arr[k];

                if (sum <= X) {
                    // All elements from j+1 to k
                    // will also form a valid triplet.
                    count += (k - j);
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        long long ans = countLessEqual(arr, r)
                      - countLessEqual(arr, l - 1);

        return (int)ans;
    }
};