class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int doubles = 0;

        for (int x : arr) {
            increments += __builtin_popcount(x);

            if (x > 0)
                doubles = max(doubles, 31 - __builtin_clz(x));
        }

        return increments + doubles;
    }
};