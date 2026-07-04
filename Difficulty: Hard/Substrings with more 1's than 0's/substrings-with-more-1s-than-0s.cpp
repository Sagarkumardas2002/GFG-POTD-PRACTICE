class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= n) {
            bit[index] += value;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
};

class Solution {
public:
    int countSubstring(string &s) {

        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1')
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1] - 1;
        }

        vector<int> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        Fenwick bit(values.size());

        long long ans = 0;

        for (int x : prefix) {

            int index = lower_bound(values.begin(), values.end(), x) - values.begin() + 1;

            ans += bit.query(index - 1);

            bit.update(index, 1);
        }

        return ans;
    }
};