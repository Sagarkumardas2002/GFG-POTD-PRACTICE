class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            // Remove elements smaller or equal to current price
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, span is i+1
            if (st.empty()) {
                span[i] = i + 1;
            } else {
                span[i] = i - st.top();
            }

            // Push current index
            st.push(i);
        }

        return span;
    }
};

