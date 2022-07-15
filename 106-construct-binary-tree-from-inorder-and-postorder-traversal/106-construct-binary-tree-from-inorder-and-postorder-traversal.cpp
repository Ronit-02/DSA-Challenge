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
    TreeNode *solve(map<int, int> &in, vector<int> post, int inStart, int inEnd, int postEnd){
    
        // base case
        if(inStart > inEnd || postEnd < 0)
            return NULL;

        TreeNode *root = new TreeNode(post[postEnd]);

        // map to find root index in inorder
        int inRoot = in[root -> val];
        int numsRight = inEnd - inRoot;

        // left subtree
        root -> left = solve(in, post, inStart, inRoot-1, postEnd-numsRight-1);
        // right subtree
        root -> right = solve(in, post, inRoot+1, inEnd, postEnd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // mapping inorder values
        map<int, int> in;
        for(int i = 0; i < inorder.size(); i++){
            in[inorder[i]] = i;     // value -> index
        }
        
        int n = inorder.size();
        return solve(in, postorder, 0, n-1, n-1);
    }
    
};