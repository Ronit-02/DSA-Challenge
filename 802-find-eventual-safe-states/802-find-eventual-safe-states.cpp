class Solution {
public:
    // Intuition: (detect cycle)
    // all the nodes which are part of a cycle or lead to a cycle 
    // are not safe nodes, rest are!
    bool dfs(vector<int> &vis, vector<int> &path, vector<vector<int>>& graph, int node){

        vis[node] = 1;  // mark it
        path[node] = 1;

        // traversing all adjacent items
        for(auto adjNode: graph[node]){

            // 1. not visited, visit it
            if(vis[adjNode] == 0){
                if(dfs(vis, path, graph, adjNode) == true)  // if detected a cycle, break out
                    return true;
            }

            // 2. visited but in same path
            else if(path[adjNode] == 1){
                return true;
            }
        }
        path[node] = 0;   
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> vis(n, 0); // visited array
        vector<int> path(n, 0);  // path-visited array

        // for multi-component graph, need to check every node
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(vis, path, graph, i);
        }
        
        vector<int> safe;

        // all marked as path = 0, are safe
        for(int i=0; i<n; i++){
            if(path[i] == 0)
                safe.push_back(i);
        }
        return safe;
    }
};