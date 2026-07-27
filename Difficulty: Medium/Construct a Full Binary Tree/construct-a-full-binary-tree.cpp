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
    unordered_map<int,int> pos;

    Node* buildUtil(vector<int> &pre, vector<int> &preMirror, int &idx, int l, int r) {
        if (idx >= (int)pre.size() || l > r) return NULL;

        Node* node = new Node(pre[idx]);
        idx++;

        if (l == r) return node;

        int i = pos[pre[idx]];  // O(1) lookup instead of linear scan

        node->left  = buildUtil(pre, preMirror, idx, i, r);
        node->right = buildUtil(pre, preMirror, idx, l + 1, i - 1);

        return node;
    }

    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = pre.size();
        for (int j = 0; j < n; j++) pos[preMirror[j]] = j;

        int idx = 0;
        return buildUtil(pre, preMirror, idx, 0, n - 1);
    }
};