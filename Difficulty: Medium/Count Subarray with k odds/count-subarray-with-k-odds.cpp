class Solution {
  public:
    
    int atMost(vector<int>& arr, int k) {
        int left = 0, oddCount = 0, ans = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] % 2 != 0)
                oddCount++;
            
            while (oddCount > k) {
                if (arr[left] % 2 != 0)
                    oddCount--;
                left++;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
};
