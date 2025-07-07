class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
      int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; ++i) {
        int index = i % n;
        while (!st.empty() && arr[index] > arr[st.top()]) {
            result[st.top()] = arr[index];
            st.pop();
        }
        if (i < n)
            st.push(index);
    }

    return result;
    }
};