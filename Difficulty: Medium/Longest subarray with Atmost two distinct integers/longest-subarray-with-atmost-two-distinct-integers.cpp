class Solution {
public:
    int totalElements(vector<int> &arr) {
        
        int n = arr.size();
        unordered_map<int,int> freq;
        
        int left = 0;
        int maxLength = 0;
        
        for(int right = 0; right < n; right++) {
            
            // Add current element
            freq[arr[right]]++;
            
            // If more than 2 distinct elements, shrink window
            while(freq.size() > 2) {
                freq[arr[left]]--;
                
                if(freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                
                left++;
            }
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};