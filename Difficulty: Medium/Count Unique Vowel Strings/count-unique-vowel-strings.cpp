class Solution {
  public:
    int vowelCount(string& s) {
      unordered_map<char, int> freq;
        string vowels = "aeiou";
        
        // Count frequency of each vowel in the string
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                freq[ch]++;
            }
        }

        int distinctVowels = freq.size();
        if (distinctVowels == 0) return 0;

        // Compute product of choices (one for each vowel)
        int combinations = 1;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            combinations *= it->second;
        }

        // Compute factorial of number of distinct vowels
        int permutations = 1;
        for (int i = 2; i <= distinctVowels; i++) {
            permutations *= i;
        }

        return combinations * permutations;
    }
};