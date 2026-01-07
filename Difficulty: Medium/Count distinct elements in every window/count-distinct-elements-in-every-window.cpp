class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        
        // First window
        for(int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        result.push_back(freq.size());
        
        // Sliding window
        for(int i = k; i < arr.size(); i++) {
            // Remove element going out of window
            freq[arr[i - k]]--;
            if(freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }
            
            // Add new element
            freq[arr[i]]++;
            
            result.push_back(freq.size());
        }
        
        return result;
    }
};
