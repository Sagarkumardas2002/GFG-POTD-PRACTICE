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
    
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        if (!head || !head->next)
            return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverse(slow);

        // Step 3: Compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;

        while (temp) {
            if (firstHalf->data != temp->data)
                return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};
