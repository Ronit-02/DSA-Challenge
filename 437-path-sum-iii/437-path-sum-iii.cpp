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
    void solve(TreeNode *root, int target, vector<int> path, int &count){
        
        // base case
        if(root == NULL)
            return;
        
        //adding
        path.push_back(root -> val);
            
        // left and right subtree
        solve(root -> left, target, path, count);
        solve(root -> right, target, path, count);
        
        // checking for req paths
        int size = path.size();
        long int sum = 0;
        for(int i = size-1; i >= 0; i--){
            
            sum += path[i];
            if(sum == target){
                count++;
            }
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
    
        vector<int> path;
        int count = 0;
        
        solve(root, targetSum, path, count);
        
        return count;
    }
};