class Solution {
public:
    // Intuition:
    // As we go coloring nodes with complement color which are not visited
    // finding a node which is visited with same color
    bool dfs(vector<int> &color, vector<vector<int>>& graph, int node){
        
        for(auto adjNode: graph[node]){
            
            // 1. not colored -> opp color, recur
            if(color[adjNode] == -1){
                color[adjNode] = !color[node];
                if(dfs(color, graph, adjNode) == false)
                    return false;
            }
            
            // 2. colored and same color
            else if(color[adjNode] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int> color(v, -1);   // color array
        
        // for multi-source graph
        for(int i=0; i<v; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(dfs(color, graph, i) == false)
                    return false;
            }
        }
        
        return true;
    }
};