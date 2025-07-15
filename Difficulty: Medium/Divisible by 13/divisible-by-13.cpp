class Solution {
  public:
    bool divby13(string &s) {
        int remainder = 0;
        for (char ch : s) {
            int digit = ch - '0';
            remainder = (remainder * 10 + digit) % 13;
        }
        return remainder == 0;
    }
};