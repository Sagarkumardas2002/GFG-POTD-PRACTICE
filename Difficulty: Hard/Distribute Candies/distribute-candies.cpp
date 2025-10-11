/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int totalMoves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Add moves required to balance children
        totalMoves += abs(left) + abs(right);

        // Return balance of candies to parent
        return root->data + left + right - 1;
    }

    int distCandy(Node* root) {
        totalMoves = 0;
        dfs(root);
        return totalMoves;
    }
};
