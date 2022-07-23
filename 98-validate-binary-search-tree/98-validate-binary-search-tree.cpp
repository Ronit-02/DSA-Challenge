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
    // Intuition: As we go to subtrees range of values that it can admitt changes
    bool solve(TreeNode *root, long min, long max){
        
        // base case
        if(root == NULL)
            return true;
        
        bool left = solve(root->left, min, root->val);
        bool right = solve(root->right, root->val, max);
        
        return left && right && (root->val < max) && (root->val > min);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return solve(root, LONG_MIN, LONG_MAX);   
    }
};