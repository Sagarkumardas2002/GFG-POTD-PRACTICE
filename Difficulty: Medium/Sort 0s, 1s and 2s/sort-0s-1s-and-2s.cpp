class Solution {
  public:
    void sort012(vector<int>& arr) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count 0s, 1s, and 2s
        for (int x : arr) {
            if (x == 0) count0++;
            else if (x == 1) count1++;
            else count2++;
        }

        int index = 0;

        // Fill 0s
        while (count0--) arr[index++] = 0;

        // Fill 1s
        while (count1--) arr[index++] = 1;

        // Fill 2s
        while (count2--) arr[index++] = 2;
    }
};
