/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
       
        vector<int>arr;
        Node * curr=head;
        
       while(curr){
           arr.push_back(curr->data);
           curr=curr->next;
       }
       
       sort(arr.begin(),arr.end());
       int start=0;
       
       curr=head;
       
       while(curr){
           curr->data=arr[start];
           curr=curr->next;
           start++;
       }
       return head;
       
    }
};