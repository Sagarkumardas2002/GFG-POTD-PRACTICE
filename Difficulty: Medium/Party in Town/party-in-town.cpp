class Solution {
  public:

    pair<int, int> bfs(int start, vector<vector<int>> &adj) {
        int n = adj.size();

        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthestNode = start;
        int maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node - 1]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);

                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }

    int partyHouse(vector<vector<int>> &adj) {
        // Find one end of the diameter
        pair<int, int> first = bfs(1, adj);
        int endNode = first.first;

        // Find the diameter
        pair<int, int> second = bfs(endNode, adj);
        int diameter = second.second;

        // Minimum maximum distance = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};