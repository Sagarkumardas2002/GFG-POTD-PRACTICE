class Solution {
  public:
       int n, m;

    bool canReach(vector<vector<int>>& mat, int limit) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({0,0});
        vis[0][0] = 1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            if(x==n-1 && y==m-1) return true;

            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]) {
                    int diff = abs(mat[x][y] - mat[nx][ny]);
                    if(diff <= limit) {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }

    int minCostPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        int low = 0, high = 1e6, ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(canReach(mat, mid)) {
                ans = mid;          // possible, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;      // not possible, try bigger
            }
        }
        return ans;
    }
};
