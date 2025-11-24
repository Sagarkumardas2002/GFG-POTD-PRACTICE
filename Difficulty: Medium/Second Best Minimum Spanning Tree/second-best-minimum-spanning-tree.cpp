#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankArr;

    DSU(int n) {
        parent.resize(n);
        rankArr.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return false;

        if (rankArr[a] < rankArr[b]) {
            parent[a] = b;
        } else if (rankArr[a] > rankArr[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rankArr[a]++;
        }
        return true;
    }
};

class Solution {
public:
    int secondMST(int V, vector<vector<int>> &edges) {

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<int> mstIndex;
        int mstWeight = 0;

        DSU dsu(V);

        // Build 1st MST
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dsu.unionSet(u, v)) {
                mstIndex.push_back(i);
                mstWeight += w;
            }
        }

        if (mstIndex.size() != V - 1) return -1;

        int secondBest = INT_MAX;

        // Try excluding each MST-edge
        for (int removeIdx : mstIndex) {

            DSU dsu2(V);
            int w2 = 0, cnt = 0;

            for (int i = 0; i < edges.size(); i++) {
                if (i == removeIdx) continue;

                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                if (dsu2.unionSet(u, v)) {
                    w2 += w;
                    cnt++;
                }
            }

            if (cnt == V - 1 && w2 > mstWeight)
                secondBest = min(secondBest, w2);
        }

        return (secondBest == INT_MAX) ? -1 : secondBest;
    }
};
