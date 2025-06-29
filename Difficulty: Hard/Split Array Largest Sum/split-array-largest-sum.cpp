class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int k, int maxSumAllowed) {
        int count = 1, currentSum = 0;
        
        for (int num : arr) {
            if (currentSum + num > maxSumAllowed) {
                count++; // start new subarray
                currentSum = num;
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int answer = high;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (isPossible(arr, k, mid)) {
                answer = mid;        // try smaller max sum
                high = mid - 1;
            } else {
                low = mid + 1;       // need larger max sum
            }
        }
    
        return answer;
    }
};