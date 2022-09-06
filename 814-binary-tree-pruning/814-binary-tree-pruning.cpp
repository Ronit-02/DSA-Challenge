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
private:
    bool dfs(TreeNode* &node){
        
        // base case
        if(node == NULL)
            return false;
        
        bool left = dfs(node->left);
        bool right = dfs(node->right);
        bool curr = node->val == 1;
        
        if(left || right || curr){
            return true;
        }
        else{
            node = NULL;
            return false;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        dfs(root);
        return root;
    }
};