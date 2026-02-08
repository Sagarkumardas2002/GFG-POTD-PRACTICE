class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            // If current element is negative, swap
            if (arr[i] < 0) {
                swap(maxEndingHere, minEndingHere);
            }

            maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
            minEndingHere = min(arr[i], minEndingHere * arr[i]);

            answer = max(answer, maxEndingHere);
        }

        return answer;
    }
};
