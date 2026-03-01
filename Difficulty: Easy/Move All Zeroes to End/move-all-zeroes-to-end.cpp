class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int index = 0;

        // Step 1: Move non-zero elements forward
        for(int i = 0; i < n; i++){
            if(arr[i] != 0){
                arr[index] = arr[i];
                index++;
            }
        }

        // Step 2: Fill remaining with zeros
        while(index < n){
            arr[index] = 0;
            index++;
        }
    }
};