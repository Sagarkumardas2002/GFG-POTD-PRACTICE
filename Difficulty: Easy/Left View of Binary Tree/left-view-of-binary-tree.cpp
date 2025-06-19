/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
     vector<int> view;
        if (!root) return view;
    
        queue<Node*> que;
        que.push(root);
    
        while (!que.empty()) {
            int nodesAtCurrentLevel = que.size();
    
            for (int i = 0; i < nodesAtCurrentLevel; ++i) {
                Node* currentNode = que.front();
                que.pop();
    
                // First node at the current level goes in the left view
                if (i == 0) view.push_back(currentNode->data);
    
                if (currentNode->left) que.push(currentNode->left);
                if (currentNode->right) que.push(currentNode->right);
            }
        }
    return view;
    }
};