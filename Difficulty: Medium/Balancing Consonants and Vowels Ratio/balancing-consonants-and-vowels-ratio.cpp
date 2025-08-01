class Solution {
  public:
   bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int countBalanced(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;

        // prefix sum map (balance → count)
        unordered_map<int, int> balanceFreq;
        balanceFreq[0] = 1;

        int balance = 0;

        for (int i = 0; i < n; ++i) {
            for (char ch : arr[i]) {
                if (isVowel(ch)) balance++;
                else balance--;
            }

            ans += balanceFreq[balance];
            balanceFreq[balance]++;
        }

        return ans;
    }
};