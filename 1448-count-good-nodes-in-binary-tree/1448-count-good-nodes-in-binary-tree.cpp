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
    // DFS Algorithm
    int dfs(TreeNode* root, int Max){
        
        if(root == NULL)
            return 0;
        
        Max = max(Max, root->val);
        
        if(root->val >= Max){
            return 1 + dfs(root->left, Max) + dfs(root->right, Max);
        }
        else{
            return dfs(root->left, Max) + dfs(root->right, Max);
        }
    }
    int goodNodes(TreeNode* root) {
        
        return dfs(root, INT_MIN);
    }
};