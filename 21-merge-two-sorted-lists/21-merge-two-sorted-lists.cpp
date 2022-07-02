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
    ListNode* solve(ListNode* list1, ListNode* list2){
        
        ListNode* curr1 = list1;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = NULL;
        
        if(next1 == NULL){    // when only 1 element is present in list1
            curr1 -> next = curr2;
            return list1;
        }
        
        while(next1 != NULL && curr2 != NULL){
            
            if((curr2-> val >= curr1-> val) && 
               (curr2-> val <= next1-> val)){
                
                // adding node in between list1
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;
                
                // updating pointers
                curr1 = curr2;
                curr2 = next2;
            }
            else{ 
                
                curr1 = next1;
                next1 = next1 -> next;
                
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        // extreme cases
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        if(list1 -> val <= list2 -> val)
            return solve(list1, list2);
        else
            return solve(list2, list1);
    }
};