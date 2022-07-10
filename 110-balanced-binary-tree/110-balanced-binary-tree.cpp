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
    // Function to take care of height and balancing together
    pair<int,bool> solve(TreeNode* root){
        
        pair<int, bool> ans;
        
        // base case
        if(root == NULL){
            pair<int,bool> p = make_pair(0,true);
            return p;
        }
        
        pair<int, bool> left = solve(root -> left);
        pair<int, bool> right = solve(root -> right);
        
        // calculating height
        ans.first = max(left.first, right.first) + 1;
        
        // calculating if balanced
        bool diff = abs(left.first - right.first) <= 1 ? true : false;
        
        if(left.second && right.second && diff)
            ans.second = true;
        else 
            ans.second = false;
        
        return ans;
        
    } 
    bool isBalanced(TreeNode* root) {
        
        return solve(root).second;
    }
};