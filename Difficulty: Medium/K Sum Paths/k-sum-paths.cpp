/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int dfs(Node* root, long long currSum, int k, unordered_map<long long,int> &prefix){
        if(root == NULL)
            return 0;
        
        currSum += root->data;
        
        int count = 0;
        
        // check if a prefix exists
        if(prefix.find(currSum - k) != prefix.end())
            count += prefix[currSum - k];
        
        // store current prefix
        prefix[currSum]++;
        
        // explore children
        count += dfs(root->left, currSum, k, prefix);
        count += dfs(root->right, currSum, k, prefix);
        
        // backtrack
        prefix[currSum]--;
        
        return count;
    }
    
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> prefix;
        
        prefix[0] = 1;   // important
        
        return dfs(root, 0, k, prefix);
    }
};