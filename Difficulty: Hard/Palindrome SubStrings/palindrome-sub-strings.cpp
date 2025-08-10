class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Expand around each possible center
        for (int center = 0; center < n; center++) {
            // Odd length palindromes
            expandFromCenter(s, center, center, count);
            // Even length palindromes
            expandFromCenter(s, center, center + 1, count);
        }
        return count;
    }

    void expandFromCenter(string &s, int left, int right, int &count) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 >= 2) // length ≥ 2
                count++;
            left--;
            right++;
        }
    }
};