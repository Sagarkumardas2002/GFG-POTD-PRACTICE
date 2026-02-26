class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        int n = s1.size();
        
        // Since only lowercase letters are allowed
        vector<char> map1(26, 0);  // s1 -> s2
        vector<char> map2(26, 0);  // s2 -> s1
        
        for(int i = 0; i < n; i++) {
            char ch1 = s1[i];
            char ch2 = s2[i];
            
            // If not mapped yet
            if(map1[ch1 - 'a'] == 0 && map2[ch2 - 'a'] == 0) {
                map1[ch1 - 'a'] = ch2;
                map2[ch2 - 'a'] = ch1;
            }
            else {
                // If mapping is inconsistent
                if(map1[ch1 - 'a'] != ch2 || map2[ch2 - 'a'] != ch1)
                    return false;
            }
        }
        
        return true;
    }
};