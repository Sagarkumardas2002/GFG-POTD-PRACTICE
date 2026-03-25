class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
      unordered_set<int>st;
      vector<int>result;
      
      for(auto it: arr){
          st.insert(it);
      }
      
      for(auto it:st){
          result.push_back(it);
      }
      
      sort(result.begin(),result.end());
        return result;
    }
};