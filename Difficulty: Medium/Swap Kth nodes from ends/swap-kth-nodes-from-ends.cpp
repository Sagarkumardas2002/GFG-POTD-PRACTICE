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
    Node* swapKth(Node* head, int k) {
         if (!head) return head;

        // Step 1: Find length of list
        int n = 0;
        Node* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        // If k is more than number of nodes → no swap
        if (k > n) return head;

        // If kth from start == kth from end → no swap
        if (2 * k - 1 == n) return head;

        // Step 2: Find kth node from start (x) and its previous (xPrev)
        Node* x = head;
        Node* xPrev = nullptr;
        for (int i = 1; i < k; i++) {
            xPrev = x;
            x = x->next;
        }

        // Step 3: Find kth node from end (y) and its previous (yPrev)
        Node* y = head;
        Node* yPrev = nullptr;
        for (int i = 1; i < n - k + 1; i++) {
            yPrev = y;
            y = y->next;
        }

        // Step 4: Fix previous pointers
        if (xPrev) xPrev->next = y;
        if (yPrev) yPrev->next = x;

        // Step 5: Swap next pointers
        Node* temp = x->next;
        x->next = y->next;
        y->next = temp;

        // Step 6: Update head if needed
        if (k == 1) head = y;
        if (k == n) head = x;

        return head;
        
    }
};