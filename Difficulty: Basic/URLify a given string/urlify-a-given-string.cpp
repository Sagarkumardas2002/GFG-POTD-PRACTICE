class Solution {
public:
    string URLify(string &s) {
        string result = "";
        
        for (char ch : s) {
            if (ch == ' ') {
                result += "%20";
            } else {
                result += ch;
            }
        }
        
        return result;
    }
};