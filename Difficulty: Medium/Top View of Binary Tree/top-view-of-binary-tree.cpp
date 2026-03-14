/*
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
    vector<int> topView(Node *root) {
        
        vector<int> result;
        if(root == NULL) return result;
        
        map<int, int> topNode; // HD -> node value
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* currentNode = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            // store only the first node for each horizontal distance
            if(topNode.find(hd) == topNode.end()) {
                topNode[hd] = currentNode->data;
            }
            
            if(currentNode->left) {
                q.push({currentNode->left, hd - 1});
            }
            
            if(currentNode->right) {
                q.push({currentNode->right, hd + 1});
            }
        }
        
        // store answer from leftmost to rightmost
        for(auto it : topNode) {
            result.push_back(it.second);
        }
        
        return result;
    }
};