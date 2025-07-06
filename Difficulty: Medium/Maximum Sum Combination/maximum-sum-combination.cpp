class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend()); // Sort both arrays in descending order
        sort(b.rbegin(), b.rend());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;

        // Start with the largest possible sum
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});

        vector<int> ans;

        while (ans.size() < k && !pq.empty()) {
            auto top = pq.top(); pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(sum);

            // Next pair (i+1, j)
            if (i + 1 < n && !vis.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }

            // Next pair (i, j+1)
            if (j + 1 < n && !vis.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }

        return ans;
    }
};

