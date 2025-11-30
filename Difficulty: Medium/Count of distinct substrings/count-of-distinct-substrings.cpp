class Solution {
public:
    vector<int> buildSuffixArray(string &s) {
        int n = s.size();
        vector<int> sa(n), ranks(n), tmp(n);
        
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            ranks[i] = s[i];
        }
        
        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (ranks[a] != ranks[b])
                    return ranks[a] < ranks[b];
                int ra = (a + k < n) ? ranks[a + k] : -1;
                int rb = (b + k < n) ? ranks[b + k] : -1;
                return ra < rb;
            };
            
            sort(sa.begin(), sa.end(), cmp);
            
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            ranks = tmp;
        }
        
        return sa;
    }
    
    vector<int> buildLCP(string &s, vector<int> &sa) {
        int n = s.size();
        vector<int> lcp(n, 0), rank(n, 0);
        
        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;
        
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
        
        return lcp;
    }
    
    int countSubs(string& s) {
        int n = s.size();
        
        vector<int> sa = buildSuffixArray(s);
        vector<int> lcp = buildLCP(s, sa);
        
        long long totalSubstrings = 1LL * n * (n + 1) / 2;
        long long repeated = 0;
        
        for (int x : lcp) repeated += x;
        
        return totalSubstrings - repeated;
    }
};
