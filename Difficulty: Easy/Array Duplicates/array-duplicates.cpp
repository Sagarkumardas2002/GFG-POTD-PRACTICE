class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++) {
            int val = abs(arr[i]);
            int idx = val - 1;

            // If already negative, number seen before → duplicate
            if(arr[idx] < 0) {
                ans.push_back(val);
            } 
            else {
                arr[idx] = -arr[idx]; // Mark visited
            }
        }

        return ans;
    }
};
