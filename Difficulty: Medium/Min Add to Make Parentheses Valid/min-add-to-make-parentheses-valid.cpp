class Solution {
  public:
    int minParentheses(string& s) {
     int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else { // ')'
                if (open > 0) {
                    open--; // match with an existing '('
                } else {
                    add++;  // need one '(' before this ')'
                }
            }
        }
        return add + open; // unmatched ')' + unmatched '('
            
    }
};