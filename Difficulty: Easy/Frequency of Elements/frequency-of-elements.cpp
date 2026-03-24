class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<vector<int>>result;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        for(auto it:mp){
            result.push_back({it.first,it.second});
        }
        return result;
        
    }
};