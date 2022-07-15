// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node *solve(int in[], int pre[], int preStart, int inStart, int inEnd, int n)
    {
        // base cases
        if(inStart > inEnd || preStart > n-1){
            return NULL;
        }
        
        Node *root = new Node(pre[preStart]);
        
        // calculating root position
        int inRoot = 0;
        for(int i = inStart; i <= inEnd; i++){
            if(root -> data == in[i])
                inRoot = i;
        }
        
        int numsLeft = inRoot - inStart;
        
        // left subtree
        root -> left = solve(in, pre, preStart+1, inStart, inRoot-1, n);
        
        // right subtree
        root -> right = solve(in, pre, preStart+numsLeft+1, inRoot+1, inEnd, n);
                            
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node *root = NULL;
        root = solve(in, pre, 0, 0, n-1, n);
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends