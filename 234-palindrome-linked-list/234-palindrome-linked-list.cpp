/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMid(ListNode* head){
       
        // slow fast method
        ListNode* slow = head;
        ListNode* fast = slow -> next;
        
        while(fast != NULL && fast -> next != NULL ){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        // when only 1 element is present
        if(head -> next == NULL){
            return true;
        }
        
        // calculating mid
        ListNode* mid = getMid(head);
        
        // reversing list after mid
        mid -> next = reverse(mid->next);
            
        // comparing operation
        ListNode* curr = head;
        ListNode* temp = mid -> next;
        
        while(temp != NULL){
            if(curr -> val != temp -> val)
                return false;
            curr = curr -> next;
            temp = temp -> next;
        }
            
        // re-reversing list after mid
        mid -> next = reverse(mid->next);
        
        return true;
    }
};