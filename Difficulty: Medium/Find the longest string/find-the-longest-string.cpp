class Solution {
  public:
    string longestString(vector<string> &words) {
        sort(words.begin(), words.end());
    unordered_set<string> validWords;
    string result = "";

    for (string& word : words) {
        if (word.size() == 1 || validWords.count(word.substr(0, word.size() - 1))) {
            validWords.insert(word);
            if (word.size() > result.size() || 
                (word.size() == result.size() && word < result)) {
                result = word;
            }
        }
    }
    return result;
        
    }
};