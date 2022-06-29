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
    ListNode *detectCycle(ListNode *head) {
        
        // Using Hashmap Technique
        unordered_map<ListNode*,int> mapping;
        
        ListNode* temp = head;
        
        int i = 0;
        while(temp != NULL){
            
            if(mapping.find(temp) != mapping.end()){
                return temp;
            }
            mapping[temp] = i++;
            temp = temp->next;
        }
        
        return NULL;
    }
};