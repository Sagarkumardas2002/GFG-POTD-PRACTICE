class Solution {
  public:
    int missingNumber(vector<int> &arr) {
       unordered_map<int, int> mp;

        for (int &it : arr) {
            if (it > 0) {
                mp[it]++;
            }
        }

        for (int i = 1; i <= arr.size() + 1; i++) {
            if (mp.find(i) == mp.end()) {
                return i;
            }
        }

        return -1;
        
    }
};