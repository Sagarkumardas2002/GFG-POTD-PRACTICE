/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    struct Info {
        int mini;
        int maxi;
        int size;
        bool isBST;
    };
    
    Info solve(Node* root, int &ans) {
        // Base case
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0, true};
        }
        
        // Left and Right
        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);
        
        Info curr;
        
        // Check BST condition
        if (left.isBST && right.isBST && 
            root->data > left.maxi && root->data < right.mini) {
            
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.mini = min(root->data, left.mini);
            curr.maxi = max(root->data, right.maxi);
            
            ans = max(ans, curr.size);
        }
        else {
            curr.isBST = false;
            curr.size = max(left.size, right.size);
            
            // These values won't matter since not BST
            curr.mini = INT_MIN;
            curr.maxi = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};