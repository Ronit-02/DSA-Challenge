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
    int nodes = 0;
    void dfs(TreeNode* root, int currMax){
        
        if(root == NULL)
            return;
        
        if(root->val >= currMax){
            nodes++;
            currMax = root->val;
        }
        
        dfs(root->left, currMax);
        dfs(root->right, currMax);
    }
    int goodNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        dfs(root, INT_MIN);
        
        return nodes;
    }
};