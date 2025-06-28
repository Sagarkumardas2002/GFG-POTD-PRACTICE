class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> result;

        // Step 1: Sort b[]
        sort(b.begin(), b.end());

        // Step 2: For each element in a[], count using upper_bound
        for (int x : a) {
            // upper_bound returns iterator to first element > x
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            result.push_back(count);
        }

        return result;
    }
};
