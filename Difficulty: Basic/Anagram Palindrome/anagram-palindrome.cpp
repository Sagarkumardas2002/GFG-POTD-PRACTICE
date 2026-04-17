class Solution {
public:
    bool canFormPalindrome(string &s) {
        int freq[26] = {0};

        // Count frequency
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        int oddCount = 0;

        // Count odd frequencies
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0) {
                oddCount++;
            }
        }

        // Check condition
        if(oddCount > 1) return false;

        return true;
    }
};