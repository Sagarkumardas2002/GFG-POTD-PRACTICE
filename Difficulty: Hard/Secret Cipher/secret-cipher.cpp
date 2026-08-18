class Solution {
public:
    string compress(string &s) {

        int n = s.size();

        // KMP prefix function / LPS
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {

            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            lps[i] = j;
        }

        string answer;

        int i = n - 1;

        while (i >= 0) {

            // Prefix length must be even
            if (i % 2 == 1) {

                int len = i + 1;
                int period = len - lps[i];

                if (lps[i] >= len / 2 &&
                    len % (2 * period) == 0) {

                    answer += '*';

                    // Skip the repeated first half
                    i = i / 2 + 1;
                }
                else {
                    answer += s[i];
                }
            }
            else {
                answer += s[i];
            }

            i--;
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};