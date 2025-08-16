class Solution {
public:
    string findLargest(vector<int> &arr) {
        vector<string> nums;
        for (int x : arr) nums.push_back(to_string(x));

        auto cmp = [](const string &a, const string &b) {
            return a + b > b + a;
        };

        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == "0") return "0";

        string result;
        for (auto &s : nums) result += s;

        return result;
    }
};
