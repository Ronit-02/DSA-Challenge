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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector< vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        // using deque as it is accessible from both sides
        deque<TreeNode *> q;
        q.push_back(root);
        
        TreeNode* temp = NULL;
        int level = 0;
        
        while (!q.empty()) {
            
            int n = q.size();
            vector<int> v;

            for (int i=0; i<n; i++) {

                // popping
                // pop from back at odd levels
                if (level % 2 == 0) { 
                    temp = q.back();
                    q.pop_back();
                }
                // pop from front at even levels
                else {
                    temp = q.front();
                    q.pop_front();
                }
                
                v.push_back(temp -> val);
                
                // pushing
                // push on front at odd levels
                if (level % 2 == 0){

                    if (temp->left) 
                        q.push_front(temp->left);
                    if (temp->right) 
                        q.push_front(temp->right);
                }
                // push on back at even levels
                else{

                    if (temp->right) 
                        q.push_back(temp->right);
                    if (temp->left) 
                        q.push_back(temp->left);
                }
            }
            
            ans.push_back(v);    
            level++;
        }
        return ans;
    }
};