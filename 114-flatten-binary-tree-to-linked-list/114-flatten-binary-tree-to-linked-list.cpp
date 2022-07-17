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
    // Morris Traversal Approach
    void flatten(TreeNode* root) {
        
        // Intuition: linking left subtree's rightmost node with current's right node
        // and repeating the process
        
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        
        while(curr != NULL){
            
            // if left subtree exists
            if(curr -> left != NULL){       
                
                // prev = left subtree rightmost node
                prev = curr -> left;
                while(prev -> right)
                    prev = prev -> right;        
            
                // linking prev with curr -> right
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left  = NULL;
            }
            
            // move to right
            curr = curr -> right;
        }
    }
};