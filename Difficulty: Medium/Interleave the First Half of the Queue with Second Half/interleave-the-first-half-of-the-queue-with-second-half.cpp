class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size() / 2;
        queue<int> firstHalf;

        // Store first half
        for (int i = 0; i < n; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Interleave first half and second half
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
