/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class nodeValue{
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

class Solution {
public:
    // Traversing left right node
    nodeValue helper(TreeNode* root, int &maxSum){
        
        // base case
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        // left and right subtree
        nodeValue left = helper(root->left, maxSum);
        nodeValue right = helper(root->right, maxSum);
        
        // root node
        nodeValue currNode;
        currNode.sum = root->val + left.sum + right.sum;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);
        
        // condition for BST
        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
            currNode.isBST = true;
        else
            currNode.isBST = false;
            
        if(currNode.isBST)
            maxSum = max(maxSum, currNode.sum);
            
        return currNode;
    }
    // Intuition: Ans is based on 4 para: min, max, valid bst(T/F), sum
    // so for that make a class
    int maxSumBST(TreeNode* root) {
     
        int maxSum = 0;
    	nodeValue temp = helper(root, maxSum);
    	
    	return maxSum;
    }
};