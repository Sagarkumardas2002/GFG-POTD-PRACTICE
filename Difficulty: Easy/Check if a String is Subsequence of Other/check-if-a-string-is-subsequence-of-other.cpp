class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
     int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        
        while (i < n && j < m) {
            if (s1[i] == s2[j]) i++;  // match character
            j++;  // always move in s2
        }
        
        return (i == n); // all chars of s1 matched
    }
};