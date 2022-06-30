// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    // Recursive approach
    int len(Node* head){
        
        if(head == NULL)
            return 0;
        
        return 1 + len(head -> next);
    }
    // Dummy node Approach
    Node* reverse(Node* head, int left, int right){
        
        Node* dummy = new Node(0);
        dummy -> next = head;
        
        // 1. placing curr = 'left' and leftPrev = '1 node before left'
        
        Node* leftPrev = dummy;
        Node* curr = head;
        
        for(int i = 0; i < left-1; i++){
            leftPrev = curr;
            curr = curr -> next;
        }
        
        // 2. Reversing nodes b/w left and right
        
        Node* next = curr -> next;
        Node* prev = NULL;
        
        for(int i=0; i < right-left+1; i++){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        // 3. Updating pointers
        
        leftPrev -> next -> next = curr;
        leftPrev -> next = prev;
        
        return dummy -> next;
    }
    Node* rotate(Node* head, int k)
    {
        int n = len(head);
        
        // edge case
        if(k >= n)
            k = k % n;
            
        if(k == 0)
            return head;
        
        head = reverse(head, 1, k);
        head = reverse(head, k+1, n);
        head = reverse(head, 1, n);
        
        return head;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends