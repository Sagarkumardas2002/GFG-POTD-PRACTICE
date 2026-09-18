/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:

    void inorder(Node* root, Node*& prev, int& ans) {
        if (root == NULL)
            return;

        inorder(root->left, prev, ans);

        if (prev != NULL) {
            ans = min(ans, root->data - prev->data);
        }

        prev = root;

        inorder(root->right, prev, ans);
    }

    int absDiff(Node *root) {
        Node* prev = NULL;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};