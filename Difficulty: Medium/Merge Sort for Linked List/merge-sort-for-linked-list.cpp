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
  
    // Function to find the middle node of the linked list
    Node*middleNode(Node*head){
          Node*slow=head;
          Node*fast=head;
          
          while(fast->next!=NULL && fast->next->next!=NULL){
              slow=slow->next;
              fast=fast->next->next;
          }
          return slow;
    }
      
    Node*mergeSortedList(Node*p1, Node*p2){
        
        // If either list is empty, return the other
        if (p1 == NULL || p2 == NULL) {
            return (p1 == NULL) ? p2 : p1;
        }
          
         Node*dummyNode=new Node(0);
         Node*current=dummyNode;
          
          while(p1!=NULL && p2!=NULL){
            if(p1->data < p2->data) {
                current->next = p1;
                p1 = p1->next;
            }
            else {
                current->next = p2;
                p2 = p2->next;
            }
               current = current->next;
          }
          
          
        // Attach remaining nodes (only one of these will run)
          if(p1 != NULL) current->next = p1;
          if(p2 != NULL) current->next = p2;
          
        return dummyNode->next; // return merged list
    }
     
    Node* mergeSort(Node* head) {
        
        // Base case: 0 or 1 node → already sorted
        if(head==NULL || head->next==NULL) return head;
        
        Node*mid=middleNode(head); // Find middle node
        Node*newHead=mid->next;
        mid->next=NULL;
        
        // Recursive sort on both halves
        Node*leftHalf=mergeSort(head);
        Node*rightHalf=mergeSort(newHead);
        
        // Merge sorted halves
        return mergeSortedList(leftHalf,rightHalf);
    }
};