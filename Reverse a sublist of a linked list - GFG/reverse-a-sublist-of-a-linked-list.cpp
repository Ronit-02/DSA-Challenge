// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
    
        Node* dummy = new Node(-1);    // dummy node to handle edge cases
        dummy -> next = head;
        
        // 1. placing curr on left position
        
        Node* curr = head;
        Node* leftPrev = dummy;
        
        for(int i = 0; i < m-1; i++){
            leftPrev = curr;
            curr = curr -> next;
        }
        
        // curr = "mth posn" and leftPrev = "just before mth posn"
        // 2. reversing list from m to n
        
        Node* tempNext = NULL;
        Node* prev = NULL;
        
        for(int i = 0; i < n-m+1; i++){
            tempNext = curr -> next;    
            curr -> next = prev;
            prev = curr;
            curr = tempNext;
        }
        
        // 3. updating pointers
        
        leftPrev -> next -> next = curr;
        leftPrev -> next = prev;
        
        return (dummy -> next);
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends