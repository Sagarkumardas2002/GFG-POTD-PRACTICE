/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;

        int sum = 0;

        // If root's data is within the range, include it
        if (root->data >= l && root->data <= r)
            sum += root->data;

        // If root's data is greater than l, explore left subtree
        if (root->data > l)
            sum += nodeSum(root->left, l, r);

        // If root's data is less than r, explore right subtree
        if (root->data < r)
            sum += nodeSum(root->right, l, r);

        return sum;
    }
};
