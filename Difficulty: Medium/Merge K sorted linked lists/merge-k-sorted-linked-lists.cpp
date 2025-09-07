/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // min-heap based on node value
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        // Push head of each non-empty list into the heap
        for (auto head : arr) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        // Dummy node to simplify list construction
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Extract smallest node and attach to merged list
        while (!minHeap.empty()) {
            Node* curr = minHeap.top();
            minHeap.pop();

            tail->next = curr;
            tail = tail->next;

            // If the extracted node has a next, push it into heap
            if (curr->next != nullptr) {
                minHeap.push(curr->next);
            }
        }

        return dummy->next;  // head of merged sorted list
    }
};