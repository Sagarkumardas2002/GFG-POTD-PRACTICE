class Solution {
  public:
    bool isPalinSent(string &s) {
        string str="";
        for(auto &it:s){
            if(isalnum(it)){
                 str+=tolower(it);
            }
           
        }
        
        int start=0;
        int end=str.size()-1;
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};