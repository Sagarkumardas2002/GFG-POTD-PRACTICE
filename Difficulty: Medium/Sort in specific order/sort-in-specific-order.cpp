class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;

        // Separate odd and even numbers
        for (int x : arr) {
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        // Sort odd descending, even ascending
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());

        // Merge back into arr
        int index = 0;
        for (int x : odd) arr[index++] = x;
        for (int x : even) arr[index++] = x;
    }
};
