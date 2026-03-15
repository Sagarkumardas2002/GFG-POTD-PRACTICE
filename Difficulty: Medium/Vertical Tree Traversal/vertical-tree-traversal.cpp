/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        map<int, vector<int>> mp; // HD -> nodes
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* current = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            mp[hd].push_back(current->data);
            
            if(current->left) {
                q.push({current->left, hd - 1});
            }
            
            if(current->right) {
                q.push({current->right, hd + 1});
            }
        }
        
        vector<vector<int>> result;
        
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};