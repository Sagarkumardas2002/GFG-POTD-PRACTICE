class Solution {
  public:
    string firstNonRepeating(string &s) {
        vector<int> freq(26, 0);   // frequency of characters
        queue<char> q;             // to maintain order
        string result = "";

        for (char ch : s) {
            freq[ch - 'a']++;
            q.push(ch);

            // remove repeating characters from front
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty())
                result += '#';
            else
                result += q.front();
        }

        return result;
    }
};
