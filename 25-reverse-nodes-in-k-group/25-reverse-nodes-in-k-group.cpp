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
    bool canReverse(ListNode* head, int k){
        
        int cnt = 0;
        while( cnt < k && head != NULL){
            head = head->next;
            cnt++;
        }
        
        if(cnt == k)    // left nodes are enough
            return true;
        else            // not enough
            return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        // base case
        if(head == NULL){
            return NULL;
        }
        
        // step 1: Reverse first k Nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int cnt = 0;
        
        if(canReverse(head, k)){    // left nodes are enough
        
            while( cnt < k && curr != NULL ){
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
            }
        
            // step 2: Recursion (1 step solve krliya, baaki recursion dekhlega)
            if(next != NULL)
                head -> next = reverseKGroup(next, k);
            
            return prev;
        }
        
        else{   // left nodes are not enough
            
            return head;
        }
    }
};