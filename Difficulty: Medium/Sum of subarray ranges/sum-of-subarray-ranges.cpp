class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevGreater(n), nextGreater(n);
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMax = 0, sumMin = 0;

        for (int i = 0; i < n; i++) {
            long long maxCount = (long long)(i - prevGreater[i]) * (nextGreater[i] - i);
            long long minCount = (long long)(i - prevSmaller[i]) * (nextSmaller[i] - i);

            sumMax += maxCount * arr[i];
            sumMin += minCount * arr[i];
        }

        return (int)(sumMax - sumMin);
    }
};
