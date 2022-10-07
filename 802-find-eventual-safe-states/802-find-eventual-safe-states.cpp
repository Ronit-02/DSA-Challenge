class Solution {
public:
    
    bool dfs(int n,vector<bool>& vis,vector<bool>& path,vector<vector<int>>& adj){
        
        vis[n] = true;
        path[n] = true;
        
        for (int node: adj[n]){
            if (!vis[node]){
                if (dfs(node,vis,path,adj))
                    return true;
            }else if (path[node]){
                 return true;
            }
        }
        path[n] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> path(n,false);
        
        for (int i=0;i<n;i++){
             if (!vis[i]){
                 dfs(i,vis,path,graph);
             }
        }
        
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (path[i]==false)
                ans.push_back(i);
        }
        return ans;
    }
};