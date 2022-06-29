/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // some extra cases
        if(head == NULL || head -> next == NULL)
            return false;
        if(head -> next == head)
            return true;
        
        // Floyd’s Cycle-Finding Algorithm / Floyd's Tortoise and Hare Algorithm
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
                return true;
        }
        
        return false;
    }
};