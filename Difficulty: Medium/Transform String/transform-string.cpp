
class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.size();
        if (n != (int)s2.size()) return -1;

        int count[256] = {0};
        for (char c : s1) count[(unsigned char)c]++;
        for (char c : s2) count[(unsigned char)c]--;
        for (int i = 0; i < 256; i++)
            if (count[i] != 0) return -1;

        int i = n - 1, j = n - 1;
        int ops = 0;
        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                ops++;
                i--;
            }
        }
        return ops;
    }
};