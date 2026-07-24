/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int longestConsecutive(Node* root) {
        if (root == nullptr)
            return -1;

        int maxLength = 1;

        function<void(Node*, int)> dfs = [&](Node* node, int currentLength) {
            if (node == nullptr)
                return;

            maxLength = max(maxLength, currentLength);

            if (node->left) {
                if (node->left->data == node->data + 1)
                    dfs(node->left, currentLength + 1);
                else
                    dfs(node->left, 1);
            }

            if (node->right) {
                if (node->right->data == node->data + 1)
                    dfs(node->right, currentLength + 1);
                else
                    dfs(node->right, 1);
            }
        };

        dfs(root, 1);

        return (maxLength == 1 ? -1 : maxLength);
    }
};