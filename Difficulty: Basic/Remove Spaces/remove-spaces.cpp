class Solution {
  public:
    string removeSpaces(string& s) {
        int index = 0;  // position to place next character
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                s[index] = s[i];
                index++;
            }
        }
        
        s.resize(index); // remove extra characters
        return s;
    }
};