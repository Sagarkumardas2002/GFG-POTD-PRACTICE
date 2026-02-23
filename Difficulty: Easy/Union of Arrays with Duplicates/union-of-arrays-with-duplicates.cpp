class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        
        // Step 1: Combine both arrays
        vector<int> combined;
        
        for(int i = 0; i < a.size(); i++) {
            combined.push_back(a[i]);
        }
        
        for(int i = 0; i < b.size(); i++) {
            combined.push_back(b[i]);
        }
        
        // Step 2: Sort the combined array
        sort(combined.begin(), combined.end());
        
        // Step 3: Remove duplicates manually
        vector<int> result;
        
        for(int i = 0; i < combined.size(); i++) {
            
            // If first element OR different from previous
            if(i == 0 || combined[i] != combined[i - 1]) {
                result.push_back(combined[i]);
            }
        }
        
        return result;
    }
};