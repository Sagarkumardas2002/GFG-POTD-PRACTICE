class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        int minLen = INT_MAX;
        int startIndex = -1;

        // Try every starting position in s1
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[0]) continue;

            int p1 = i, p2 = 0;

            // Step 1: Forward match s2 as subsequence
            while (p1 < n && p2 < m) {
                if (s1[p1] == s2[p2]) {
                    p2++;
                }
                p1++;
            }

            // If full s2 matched
            if (p2 == m) {
                int end = p1 - 1;

                // Step 2: Backtrack to minimize window
                p2 = m - 1;
                p1 = end;

                while (p1 >= i) {
                    if (s1[p1] == s2[p2]) {
                        p2--;
                        if (p2 < 0) break;
                    }
                    p1--;
                }

                int windowStart = p1;
                int windowLen = end - windowStart + 1;

                // Update answer
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = windowStart;
                }
            }
        }

        if (startIndex == -1) return "";
        return s1.substr(startIndex, minLen);
    }
};
