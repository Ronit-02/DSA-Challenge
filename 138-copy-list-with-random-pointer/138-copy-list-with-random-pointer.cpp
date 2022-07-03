/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int val){
        
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail -> next = NULL;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
            tail -> next = NULL;
        }
    }
    Node* copyRandomList(Node* head) {
        
        // 1. create a clone list
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* curr1 = head;
        
        while(curr1 != NULL){
            insertAtTail(cloneHead, cloneTail, curr1 -> val);
            curr1 = curr1 -> next;
        }
        
        // 2. Add clone Node in between original Node by changing links
        
        curr1 = head;
        Node* curr2 = cloneHead;
        
        while(curr1 != NULL){
            Node* next = curr1 -> next;
            curr1 -> next = curr2;
            curr1 = next;
            
            next = curr2 -> next;
            curr2 -> next = curr1;
            curr2 = next;
        }
        
        // 3. updating random pointers
        
        Node* temp = head;
        
        while(temp != NULL){
            
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random != NULL 
                    ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }
        
        // 4. revert changes done in step 2
        
        curr1 = head;
        curr2 = cloneHead;
        
        while(curr1 != NULL){
            curr1 -> next = curr2 -> next;
            curr1 = curr1 -> next;
            
            if(curr1 != NULL)
                curr2 -> next = curr1 -> next;
            curr2 = curr2 -> next; 
        }
        
        return cloneHead;
    }
};