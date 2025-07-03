class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxLen = -1, winStart = 0;

        for (int winEnd = 0; winEnd < n; winEnd++) {
            mp[s[winEnd]]++;

            while (mp.size() > k) {
                mp[s[winStart]]--;
                if (mp[s[winStart]] == 0) mp.erase(s[winStart]);
                winStart++;
            }

            if (mp.size() == k) {
                maxLen = max(maxLen, winEnd - winStart + 1);
            }
        }

        return maxLen;
    }
};