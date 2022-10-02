class Solution {
    int parent[26];
    int find(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = find(parent[node]);   // path compression
    }
public:
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        
        // 1. Establishing unions
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<n; i++){
            if(equations[i][1] == '='){
                
                int x = (equations[i][0] - 'a');
                int y = (equations[i][3] - 'a');
                parent[find(y)] = find(x);
            }
        }
        
        // 2. finding inequalities
        for(int i=0; i<n; i++){
            if(equations[i][1] == '!'){
                
                int x = (equations[i][0] - 'a');
                int y = (equations[i][3] - 'a');
                if(find(y) == find(x))
                    return false;
            }
        }
        
        return true;
    }
};