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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int sz = 0;
        
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        
        if(sz == 1)
            return NULL;
        
        n = sz - n - 1;
        
        if(n == -1){
            head = head->next;
            return head;
        }
        
        temp = head;
        while(n != 0 && temp != NULL){
            temp = temp->next;
            n--;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};