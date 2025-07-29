class Solution {
  public:
    vector<int> asciirange(string& s) {
       unordered_map<char, pair<int,int>>pos;
       vector<int>result;
       int n=s.size();
       
       for(int i=0;i<n;i++){
           if(pos.find(s[i])!=pos.end()){
               pos[s[i]].second=i;
           }else{
               pos[s[i]]={i,i};
           }
       }
       
       for(auto &[ch,p]:pos){
           int start=p.first;
           int end=p.second;
            if(start<end){
                int sum=0;
                for(int i=start+1;i<end;i++){
                   
                   sum+=(int)s[i];
                }
               if(sum>0){
                   result.push_back(sum);
               } 
           }
           
       }
       return result;
        
    }
};