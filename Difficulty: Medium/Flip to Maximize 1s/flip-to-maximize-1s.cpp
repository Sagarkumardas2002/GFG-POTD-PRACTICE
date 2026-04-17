class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;

        // Step 1: Count total 1s
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) totalOnes++;
        }

        // Step 2: Apply Kadane's on transformed array
        int currentSum = 0, maxSum = 0;

        for(int i = 0; i < arr.size(); i++) {
            int value;

            if(arr[i] == 0) value = 1;   // gain
            else value = -1;            // loss

            currentSum = max(value, currentSum + value);
            maxSum = max(maxSum, currentSum);
        }

        // Step 3: Add gain to original 1s
        return totalOnes + maxSum;
    }
};