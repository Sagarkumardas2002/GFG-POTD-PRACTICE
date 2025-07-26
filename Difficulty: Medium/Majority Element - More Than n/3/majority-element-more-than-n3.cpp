class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int,int>mp;
        for(int &it:arr){
            mp[it]++;
        }
        
        vector<int>result;
        for(auto &it:mp){
            if(it.second>n/3){
                result.push_back(it.first);
            }
        }
        sort(result.begin(),result.end());
        return result;
        
    }
};