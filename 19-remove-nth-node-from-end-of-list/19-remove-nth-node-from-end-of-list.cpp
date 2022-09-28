class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* end=head;
        int k=0;
        while(end){
            if(k<=n){
                k++;
            }else{
               temp=temp->next; 
            }
            end=end->next;
        }
        if(k==n){ // if wants to delete head
            return head->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};