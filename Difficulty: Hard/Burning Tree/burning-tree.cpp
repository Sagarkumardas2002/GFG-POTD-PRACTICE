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
  
    // Step 1: Map parents and find target node
    Node* markParents(Node* root, unordered_map<Node*, Node*>& parent, int target) {
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode = NULL;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->data == target) {
                targetNode = curr;
            }
            
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return targetNode;
    }

    int minTime(Node* root, int target) {
        
        unordered_map<Node*, Node*> parent;
        Node* targetNode = markParents(root, parent, target);
        
        // Step 2: BFS to burn tree
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool isBurned = false;
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                // left
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    isBurned = true;
                }
                
                // right
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    isBurned = true;
                }
                
                // parent
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                    isBurned = true;
                }
            }
            
            // if any node burned in this second
            if (isBurned) time++;
        }
        
        return time;
    }
};