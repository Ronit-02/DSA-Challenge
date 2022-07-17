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
    int solve(TreeNode* root, int &ans){
        
        // base case
        if(root == NULL)
            return 0;
        
        int left = max(0, solve(root -> left, ans));
        int right = max(0, solve(root -> right, ans));
        
        int pathSum = left + right + root -> val;
        ans = max(ans, pathSum);
            
        return max(left + root->val, right + root->val);
    }
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        int x = solve(root, ans);
        
        return ans;
    }
};