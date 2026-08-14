class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> seq;

        long long sum = s;
        seq.push_back(s);

        for (int a : arr) {
            long long next = sum + a;

            // Numbers only increase, so anything > x
            // can never be part of a subset summing to x.
            if (next > x)
                break;

            seq.push_back(next);
            sum += next;
        }

        long long rem = x;

        // Greedy from largest to smallest
        for (int i = (int)seq.size() - 1; i >= 0; i--) {
            if (seq[i] <= rem) {
                rem -= seq[i];
            }

            if (rem == 0)
                return true;
        }

        return false;
    }
};