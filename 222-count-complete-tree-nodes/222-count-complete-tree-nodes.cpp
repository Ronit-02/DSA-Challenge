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
    int leftHeight(TreeNode *root){
        
        // base case
        if(root == NULL)
            return 0;
        
        return 1 + leftHeight(root -> left);
    }
    int rightHeight(TreeNode *root){
        
        // base case
        if(root == NULL)
            return 0;
        
        return 1 + rightHeight(root -> right);
    }
    // Using Complete BT properties to find soln in O(log n)
    // property: 
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh)    // complete subtree, nodes = 2*h - 1
            return (1<<lh) - 1;   
        else
            return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};