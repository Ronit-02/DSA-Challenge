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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return head;
        
        // 1. length of linked list
        
        int len = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            prev = curr;
            curr = curr -> next;
            len++;
        }
        k = k % len;   // adjusting k
        k = len - k;
        
        // 2. making it circular
        
        prev -> next = head;
        
        // 3. (k-1)th node = NULL, kth node = Head
        
        prev = NULL;
        curr = head;
        for(int i=0; i<k; i++){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
        head = curr;
        
        return head;
    }
};