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
    // Using Morris Traversal
    // TC: O(N)
    // SC: O(1)
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode *curr = root;
        int ans = 0;
        
        while(curr != NULL){
            
            // left subtree not present
            if(curr -> left == NULL){
                
                if(--k == 0)            // condition
                    ans = curr->val;
                
                curr = curr -> right;
            }
            
            // left subtree present
            // point its predecessor (rightmost of left subtree)
            else{
                
                TreeNode* prev = curr->left;
                
                while(prev -> right && prev -> right != curr){
                    prev = prev->right;
                }
                // create link
                if(prev -> right == NULL){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                // remove link
                else{
                    
                    if(--k == 0)           // condition
                        ans = curr->val;
                    
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};