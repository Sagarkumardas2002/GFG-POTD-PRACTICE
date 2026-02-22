class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> prefixFreq;
        
        int xr = 0;        // running XOR
        long count = 0;    // result
        
        for(int i = 0; i < arr.size(); i++) {
            xr = xr ^ arr[i];   // update prefix XOR
            
            // case 1: subarray from index 0 to i
            if(xr == k) count++;
            
            // case 2: check if (xr ^ k) seen before
            int needed = xr ^ k;
            if(prefixFreq.find(needed) != prefixFreq.end()) {
                count += prefixFreq[needed];
            }
            
            // store current prefix XOR
            prefixFreq[xr]++;
        }
        
        return count;
    }
};