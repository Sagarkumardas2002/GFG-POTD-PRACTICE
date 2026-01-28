class Solution {
public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        vector<long long> leftSums, rightSums;

        // All subset sums of left part
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < left.size(); i++) {
                if (mask & (1 << i))
                    sum += left[i];
            }
            leftSums.push_back(sum);
        }

        // All subset sums of right part
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < right.size(); i++) {
                if (mask & (1 << i))
                    sum += right[i];
            }
            rightSums.push_back(sum);
        }

        unordered_map<long long, int> freq;
        for (long long s : rightSums)
            freq[s]++;

        int count = 0;
        for (long long s : leftSums) {
            long long need = k - s;
            if (freq.count(need))
                count += freq[need];
        }

        return count;
    }
};
