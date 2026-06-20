class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        
        // a^0 = 1
        if (b == "0") {
            return 1;
        }

        int lastDigit = a.back() - '0';

        // Find b % 4
        int power = 0;
        for (char ch : b) {
            power = (power * 10 + (ch - '0')) % 4;
        }

        if (power == 0) {
            power = 4;
        }

        int result = 1;
        for (int i = 0; i < power; i++) {
            result = (result * lastDigit) % 10;
        }

        return result;
    }
};