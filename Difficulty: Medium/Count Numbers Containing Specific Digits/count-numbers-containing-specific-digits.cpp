class Solution {
  public:
  
  int countForbiddenNumbers(int n, const vector<int>& forbidden) {
    if (forbidden.empty()) return 0;
    unordered_set<int> forb(forbidden.begin(), forbidden.end());
    int validLeading = 0;
    for (int d : forbidden) {
        if (d != 0) validLeading++;
    }
    if (validLeading == 0) return 0;
    int total = validLeading * pow((int)forbidden.size(), n - 1);
    return total;
      
  }

    
    int countValid(int n, vector<int>& arr) {
        vector<bool> isAllowed(10, false);
        for (int d : arr) isAllowed[d] = true;
        int total_n_digit = 9 * pow(10, n - 1);
        vector<int> forbidden;
        for (int i = 0; i <= 9; i++) {
            if (!isAllowed[i]) forbidden.push_back(i);
        }
        int forbiddenCount = countForbiddenNumbers(n, forbidden);
        return total_n_digit - forbiddenCount;
    }
};
