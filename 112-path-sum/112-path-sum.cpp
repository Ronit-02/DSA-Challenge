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
    void solve(TreeNode* root, int target, int sum, bool &ans){
        
        // base case
        if(root == NULL)
            return;
        
        sum += root -> val;
        
        // leaf node
        if(root -> left == NULL && root -> right == NULL && sum == target){
            ans = true;
            return;
        }
        
        solve(root->left, target, sum, ans);
        solve(root->right, target, sum, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool ans = false;
        int sum = 0;
        
        solve(root, targetSum, sum, ans);
        
        return ans;
    }
};