/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Loop detected
            // Step 2: Count the loop length
            int count = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                temp = temp->next;
                count++;
            }
            return count;
        }
    }

    return 0;
        
    }
};