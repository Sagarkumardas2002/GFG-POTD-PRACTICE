class Solution {
  public:
    string minWindow(string &s, string &p) {
        
        unordered_map<char,int> freq;
        unordered_set<char> st;
        
        for(char c : p){
            freq[c]++;
            st.insert(c);
        }
        
        int left = 0;
        int count = p.size();
        int minLen = INT_MAX;
        int startIndex = -1;
        
        for(int right = 0; right < s.size(); right++){
            
            if(st.count(s[right])){
                if(freq[s[right]] > 0)
                    count--;
                
                freq[s[right]]--;
            }
            
            while(count == 0){
                
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIndex = left;
                }
                
                if(st.count(s[left])){
                    freq[s[left]]++;
                    
                    if(freq[s[left]] > 0)
                        count++;
                }
                
                left++;
            }
        }
        
        if(startIndex == -1) return "";
        
        return s.substr(startIndex, minLen);
    }
};