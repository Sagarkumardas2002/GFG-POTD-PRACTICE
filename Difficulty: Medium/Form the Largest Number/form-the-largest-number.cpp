class Solution {
  public:
  
    // Custom comparator
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
  
    string findLargest(vector<int> &arr) {
        
        vector<string> nums;
        
        // Convert int to string
        for(int i = 0; i < arr.size(); i++) {
            nums.push_back(to_string(arr[i]));
        }
        
        // Sort using custom comparator
        sort(nums.begin(), nums.end(), compare);
        
        // If largest element is "0", all are zeros
        if(nums[0] == "0") return "0";
        
        // Concatenate result
        string result = "";
        for(int i = 0; i < nums.size(); i++) {
            result += nums[i];
        }
        
        return result;
    }
};