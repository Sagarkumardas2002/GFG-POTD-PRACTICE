class Solution {
public:
    int substrCount(string &s, int k) {
        int n = s.size();
        if (k > n) return 0;

        unordered_map<char, int> freq;
        int distinct = 0;
        int count = 0;

        // Build first window
        for (int i = 0; i < k; i++) {
            if (freq[s[i]] == 0) distinct++;
            freq[s[i]]++;
        }
        if (distinct == k - 1) count++;

        // Slide window
        for (int i = k; i < n; i++) {
            char out = s[i - k];  // character going out
            char in = s[i];       // character coming in

            // Remove out-going char
            freq[out]--;
            if (freq[out] == 0) distinct--;

            // Add in-coming char
            if (freq[in] == 0) distinct++;
            freq[in]++;

            if (distinct == k - 1) count++;
        }

        return count;
    }
};
