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
class Solution {
public:
    // iterative approach
    void inorder(TreeNode *root, vector<int> &in){
        
        if(root == NULL)
            return;
        
        inorder(root -> left, in);
        in.push_back(root -> val);        
        inorder(root -> right, in);
    }
    TreeNode *inorderBST(int s, int e, vector<int> &in){
        
        if(s > e)
            return NULL;
        
        int mid = s + (e-s)/2;
        TreeNode *root = new TreeNode(in[mid]);
        
        root -> left = inorderBST(s, mid-1, in);
        root -> right = inorderBST(mid+1, e, in);
        
        return root;
    }
    // Intuition: using property of bst: inorder is sorted
    // TC: O(N)
    // SC: O(N)
    TreeNode* balanceBST(TreeNode* root) {
        
        // 1: calculating inorder traversal
        vector<int> in;
        inorder(root, in);
        
        // 2: creating bst using inorder
        TreeNode *newRoot = inorderBST(0, in.size()-1, in);
        
        return newRoot;
    }
};