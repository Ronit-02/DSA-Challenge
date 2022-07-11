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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // we are working with 3 things: node, its vertical, its level
        // queue(node, vertical, lvl)
        // map[vertical][lvl] = {nodes data}
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            
            // taking front value
            pair<TreeNode * , pair<int,int> > temp = q.front();
            q.pop();
            
            // inserting in map
            TreeNode* node = temp.first;
            int v = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[v][lvl].insert(node -> val);
            
            // left subtree
            if(node -> left){
                q.push({node->left, {v-1, lvl+1}});
            }
            
            // right subtree
            if(node -> right){
                q.push({node->right, {v+1, lvl+1}});            
            }
        }
        
        // extracting answer from the map
        vector<vector<int>> ans;
        
        for(auto i: nodes){   // for a vertical
            vector<int> col;
            for(auto j: i.second){   //  for a lvl, inserting the entire muliset in vector     
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};