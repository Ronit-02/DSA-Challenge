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
    void helper(TreeNode* root, int &nodes, int Max){
        
        if(root == NULL)
            return;
        
        if(root->val >= Max){
            nodes++;
            Max = root->val;
        }
        
        helper(root->left, nodes, Max);
        helper(root->right, nodes, Max);
    }
    int goodNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int nodes = 0;
        helper(root, nodes, INT_MIN);
        
        return nodes;
    }
};