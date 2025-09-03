/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
       if (!head || !head->next) return head; // empty or single node
    
    // Step 1: Store values in array
    vector<int> arr;
    Node* temp = head;
    while (temp) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    // Step 2: Assign values from array in reverse order using while loop
    temp = head;
    int n = arr.size() - 1;  // last index
    while (temp && n >= 0) {
        temp->data = arr[n];
        temp = temp->next;
        n--;
    }

    return head;
        
    }
};