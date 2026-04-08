class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            // move left if already 0
            if (arr[left] == 0) {
                left++;
            }
            // move right if already 1
            else if (arr[right] == 1) {
                right--;
            }
            // swap when left=1 and right=0
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};