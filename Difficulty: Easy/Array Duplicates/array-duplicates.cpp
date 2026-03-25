class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
       int n=arr.size();
       vector<int>result;
       
       unordered_map<int,int>mp;
       
       for(auto it:arr){
           mp[it]++;
       }
       
      
      for(auto it:mp){
          if(it.second>1){
              result.push_back(it.first);
          }
      }
       return result;
    }
};
