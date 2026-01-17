class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                // Check content inside brackets
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // Pop opening bracket '('
                if (!st.empty()) st.pop();

                // If no operator found, it's redundant
                if (!hasOperator) return true;
            } 
            else {
                st.push(ch);
            }
        }
        return false;
    }
};
