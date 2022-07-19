/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Iterative bfs apporach
    void createMapping(TreeNode* root, map <TreeNode*, TreeNode*> &nodeParent){
        
        queue <TreeNode*> q;
        q.push(root);
        
        nodeParent[root] = NULL;
        
        while(!q.empty()){
            
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr -> left){
                nodeParent[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                nodeParent[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
    
    // " Recursive Approach for the same gave TLE " 
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // step 1: mapping for node to parent
        map <TreeNode*, TreeNode*> nodeParent;
        createMapping(root, nodeParent);
        
        // step 2: using visited map, visit all nodes from target node
        map <TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        int level = 0;
        
        while(!q.empty()){
            
            if(level == k) 
                break;
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                
                TreeNode *curr = q.front();
                q.pop();
                
                // left, right, parent
                if(curr -> left && !visited[curr -> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                if(curr -> right && !visited[curr -> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                if(nodeParent[curr] && !visited[nodeParent[curr]]){
                    q.push(nodeParent[curr]);
                    visited[nodeParent[curr]] = true;
                }
            }
            level++;
        }
        
        vector <int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};