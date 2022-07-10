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
    int height(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        // base case
        if(root == NULL)
            return true;
        
        int h1 = height(root -> left);
        int h2 = height(root -> right);
        
        if(abs(h1 - h2) <= 1 && isBalanced(root->left) && isBalanced(root -> right))
            return true;
        else
            return false;
    }
};