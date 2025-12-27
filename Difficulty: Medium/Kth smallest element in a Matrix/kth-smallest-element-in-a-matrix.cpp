class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        
        // min heap: {value, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // push first element of each row
        for (int i = 0; i < n; i++) {
            pq.push({mat[i][0], i, 0});
        }

        int answer = 0;

        while (k--) {
            auto [value, row, col] = pq.top();
            pq.pop();
            answer = value;

            // push next element from same row
            if (col + 1 < n) {
                pq.push({mat[row][col + 1], row, col + 1});
            }
        }

        return answer;
    }
};
