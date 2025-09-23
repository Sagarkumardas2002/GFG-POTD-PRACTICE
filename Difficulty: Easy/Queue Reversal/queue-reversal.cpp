class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
    
        // Push all elements of queue into stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
    
        // Push back from stack to queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    
 
    }
};