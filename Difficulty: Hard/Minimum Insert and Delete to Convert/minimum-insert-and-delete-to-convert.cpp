class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {

        unordered_map<int, int> index;

        for (int i = 0; i < b.size(); i++) {
            index[b[i]] = i;
        }

        vector<int> sequence;

        for (int num : a) {
            if (index.find(num) != index.end()) {
                sequence.push_back(index[num]);
            }
        }

        vector<int> lis;

        for (int x : sequence) {

            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        int lcs = lis.size();

        return (a.size() - lcs) + (b.size() - lcs);
    }
};