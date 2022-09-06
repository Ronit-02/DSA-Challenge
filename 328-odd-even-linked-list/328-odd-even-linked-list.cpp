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
private:
    int len(ListNode *node){
        
        if(node == NULL) return 0;
        return 1 + len(node->next);
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(len(head) < 3)
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* tempHead = head->next;
        
        ListNode* adv = head->next->next;
        int cnt = 1;
        
        while(adv != NULL){
            if(cnt % 2 != 0){
                p1-> next = adv;
                p1 = p1->next;
            }
            else{
                p2-> next = adv;
                p2 = p2->next;
            }
            adv = adv->next;
            cnt++;
        }
        
        p1->next = tempHead;
        p2->next = NULL;
        
        return head;
    }
};