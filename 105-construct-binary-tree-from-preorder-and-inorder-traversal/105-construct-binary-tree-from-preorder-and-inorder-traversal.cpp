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
    TreeNode *solve(vector<int>& in, vector<int>& pre, int preStart, int inStart, int inEnd)
    {
        // base cases
        if(inStart > inEnd || preStart > pre.size()-1){
            return NULL;
        }
        
        TreeNode *root = new TreeNode(pre[preStart]);
        
        // calculating root position in inorder
        int inRoot = 0;
        
        for(int i = inStart; i <= inEnd; i++){
            if(root -> val == in[i])
                inRoot = i;
        }
        
        // left subtree
        root -> left = solve(in, pre, preStart + 1, inStart, inRoot - 1);
        
        // right subtree
        root -> right = solve(in, pre, preStart + inRoot - inStart + 1, inRoot + 1, inEnd);
                            
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return solve(inorder, preorder, 0, 0, inorder.size()-1);
    }
};