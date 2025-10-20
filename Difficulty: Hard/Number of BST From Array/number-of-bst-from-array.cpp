class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Precompute Catalan numbers (up to 6 as per constraints)
        vector<long long> catalan(7, 0);
        catalan[0] = 1;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 0; j < i; ++j) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        // Step 2: Sort the array (BST depends on sorted order)
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        // Step 3: For each element, calculate BST count
        vector<int> result;
        for (int x : arr) {
            int L = 0, R = 0;
            for (int val : sorted_arr) {
                if (val < x) L++;
                else if (val > x) R++;
            }
            long long ways = catalan[L] * catalan[R];
            result.push_back((int)ways);
        }

        return result;
    }
};
