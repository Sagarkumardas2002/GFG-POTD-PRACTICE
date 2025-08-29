class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (s.size() < p.size()) return "";

        vector<int> target(26, 0), window(26, 0);
        for (char c : p) target[c - 'a']++;

        int required = 0;
        for (int i = 0; i < 26; i++) {
            if (target[i] > 0) required++;
        }

        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX, startIndex = -1;

        while (r < s.size()) {
            int idx = s[r] - 'a';
            window[idx]++;

            if (target[idx] > 0 && window[idx] == target[idx]) {
                formed++;
            }

            // Try to shrink window from left
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                int leftIdx = s[l] - 'a';
                window[leftIdx]--;
                if (target[leftIdx] > 0 && window[leftIdx] < target[leftIdx]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};
