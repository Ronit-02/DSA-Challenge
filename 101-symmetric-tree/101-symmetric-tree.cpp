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
    bool helper(TreeNode* left, TreeNode* right){
        
        queue <pair<TreeNode*, TreeNode*>> q;
        q.push({left, right});
        
        while(!q.empty()){
            
            pair<TreeNode*, TreeNode*> curr = q.front();
            q.pop();
            
            TreeNode* l = curr.first;
            TreeNode* r = curr.second;
            
            if(!l && !r) continue;   // both NULL
            if(!l || !r) return false;  // one is NULL
            if(l->val != r->val) return false;  // value not equal
            
            q.push({l->left, r->right});
            q.push({l->right, r->left});
        }
        
        return true;
    }
    // BFS - Iterative Approach
    bool isSymmetric(TreeNode* root) {
        
        return helper(root -> left, root -> right);
    }
};