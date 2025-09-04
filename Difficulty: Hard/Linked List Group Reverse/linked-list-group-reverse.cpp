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
    Node *reverseKGroup(Node *head, int k) {
         if (!head || k == 1) return head;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        int count = 0;
        Node* temp = head;

        // Count total nodes
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Reverse in groups
        Node* newHead = NULL;
        Node* groupPrev = NULL;

        while (count > 0) {
            curr = head;
            prev = NULL;

            int groupSize = (count >= k) ? k : count;  // if not enough nodes left, take remaining
            int n = groupSize;

            // Reverse this group of 'groupSize'
            while (n-- && curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // New head for the first group
            if (!newHead) {
                newHead = prev;
            }

            // Connect with previous group
            if (groupPrev) {
                groupPrev->next = prev;
            }

            // Move groupPrev to end of this group
            groupPrev = head;

            // Move head to next group
            head = curr;

            count -= groupSize;
        }

        return newHead;

        
    }
};