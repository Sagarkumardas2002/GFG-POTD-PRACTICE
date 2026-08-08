
class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        // Already connected -> redundant edge
        if (u == v)
            return false;

        if (rank_[u] < rank_[v])
            swap(u, v);

        parent[v] = u;

        if (rank_[u] == rank_[v])
            rank_[u]++;

        return true;
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank_.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int extra = 0;

        // Build components and count redundant edges
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                extra++;
            }
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};

