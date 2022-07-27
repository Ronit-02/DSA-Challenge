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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // base case
        if(root1 == NULL && root2 == NULL)
            return NULL;
    
        // creating new tree node
        int val1 = (root1 != NULL) ? root1->val : 0;
        int val2 = (root2 != NULL) ? root2->val : 0;
        TreeNode *root = new TreeNode(val1 + val2);
        
        // handling all cases
        root -> left = mergeTrees((root1!=NULL)? root1->left: NULL, (root2 != NULL)? root2->left: NULL);
        root -> right = mergeTrees((root1!=NULL)? root1->right: NULL, (root2 != NULL)? root2->right: NULL);
        
        return root;
    }
};