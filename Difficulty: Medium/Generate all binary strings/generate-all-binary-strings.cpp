class Solution {
  public:
    vector<string> binstr(int n) {
              vector<string> res;
        if (n < 0) return res;
        if (n == 0) { res.push_back(""); return res; } // optional: if n==0, one empty string
    
        int total = 1 << n; // 2^n
        res.reserve(total);
    
        for (int i = 0; i < total; ++i) {
            string s;
            s.resize(n);
            // build string from most-significant bit to least-significant
            for (int j = 0; j < n; ++j) {
                // bit (n-1-j) is the (most-significant first)
                s[j] = ((i >> (n - 1 - j)) & 1) ? '1' : '0';
            }
            res.push_back(s);
        }
        return res;
    }
};