/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:

    void findLeafCosts(Node* root, int level, vector<int>& costs) {
        if (root == NULL)
            return;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            costs.push_back(level);
            return;
        }

        findLeafCosts(root->left, level + 1, costs);
        findLeafCosts(root->right, level + 1, costs);
    }

    int getCount(Node *root, int k) {
        vector<int> costs;

        // Find the cost of every leaf
        findLeafCosts(root, 1, costs);

        // Visit cheapest leaves first
        sort(costs.begin(), costs.end());

        int count = 0;
        int totalCost = 0;

        for (int cost : costs) {
            if (totalCost + cost > k)
                break;

            totalCost += cost;
            count++;
        }

        return count;
    }
};