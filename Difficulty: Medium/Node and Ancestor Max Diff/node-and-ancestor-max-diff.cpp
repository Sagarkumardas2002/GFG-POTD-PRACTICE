/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:

    pair<int, int> solve(Node* root) {
        // {minimum value in subtree, maximum difference}
        if (root == NULL)
            return {INT_MAX, INT_MIN};

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return {root->data, INT_MIN};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int minDescendant = min(left.first, right.first);

        int currDiff = root->data - minDescendant;

        int maxDiff = max({currDiff, left.second, right.second});

        int minValue = min(root->data, minDescendant);

        return {minValue, maxDiff};
    }

    int maxDiff(Node* root) {
        return solve(root).second;
    }
};