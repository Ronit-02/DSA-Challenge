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
    TreeNode *solve(vector<int> in, vector<int> post, int inStart, int inEnd, int postEnd){
    
        // base case
        if(inStart > inEnd || postEnd < 0)
            return NULL;

        TreeNode *root = new TreeNode(post[postEnd]);

        // calculating root index in inorder
        int inRoot = 0;
        for(int i = inStart; i <= inEnd; i++){
            if(root -> val == in[i])
                inRoot = i;
        }

        int numsRight = inEnd - inRoot;

        // left subtree
        root -> left = solve(in, post, inStart, inRoot-1, postEnd-numsRight-1);
        // right subtree
        root -> right = solve(in, post, inRoot+1, inEnd, postEnd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        return solve(inorder, postorder, 0, n-1, n-1);
    }
    
};