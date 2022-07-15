// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void nodeToParent(Node* root, map<Node*, Node*> &nodeMap){
        
        // left node
        if(root -> left){
            nodeMap[root -> left] = root;
            nodeToParent(root -> left, nodeMap);
        }
        
        // right node
        if(root -> right){
            nodeMap[root -> right] = root;
            nodeToParent(root -> right, nodeMap);
        }
    }
    // Level order traversal
    Node *targetNode(Node *root, int target){
        
        Node *res = root;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()){
            
            Node *temp = q.front();
            q.pop();
            
            if(temp -> data == target)
                res = temp;
            
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
        
        return res;
    }
    int burnTree(Node *root, map<Node*, Node*> &nodeMap){
        
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        // level order traversal
        while(!q.empty()){
            
            int flag = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                
                Node *front = q.front();
                q.pop();
                
                // processing neighbouring nodes
                if(front -> left && !visited[front -> left]){
                    q.push(front -> left);
                    visited[front -> left] = true;
                    flag = 1;
                }
                if(front -> right && !visited[front -> right]){
                    q.push(front -> right);
                    visited[front -> right] = true;
                    flag = 1;
                }
                if(nodeMap[front] && !visited[nodeMap[front]]){
                    q.push(nodeMap[front]);
                    visited[nodeMap[front]] = true;
                    flag = 1;
                }
            }
            if(flag == 1)
                ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // step 1: create nodeToParent mapping
        map<Node*, Node*> nodeMap;
        
        nodeMap[root] = NULL;
        nodeToParent(root, nodeMap);
        
        // step 2: find target node
        Node *mid = targetNode(root, target);
        
        // step 3: burn the tree in min time
        int ans = burnTree(mid, nodeMap);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends