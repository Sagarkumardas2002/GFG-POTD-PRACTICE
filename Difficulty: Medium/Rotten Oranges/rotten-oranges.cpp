class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        int freshCount = 0;

        // Step 1: count fresh + push rotten
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Directions (up, down, left, right)
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        int time = 0;

        // Step 2: BFS
        while(!q.empty() && freshCount > 0) {
            int size = q.size();
            time++;

            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                for(int k = 0; k < 4; k++) {
                    int newRow = row + drow[k];
                    int newCol = col + dcol[k];

                    // Check valid & fresh
                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       mat[newRow][newCol] == 1) {

                        mat[newRow][newCol] = 2; // rot it
                        freshCount--;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        // Step 3: check
        if(freshCount > 0) return -1;
        return time;
    }
};