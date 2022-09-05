/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        queue <Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> nodes;
            
            for(int i=0; i<size; i++){
                
                Node* top = q.front();
                nodes.push_back(top->val);
                q.pop();
                
                
                for(int j=0; j<top->children.size(); j++){
                    q.push(top->children[j]);
                }
            }
            
            ans.push_back(nodes);
        }
        
        return ans;
    }
};