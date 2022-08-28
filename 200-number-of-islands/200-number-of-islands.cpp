class Solution {
private:
    // Recursive Approach
    void helper(vector<vector<int>> &vis, vector<vector<char>>& grid, int i, int j){
        
        // out of bounds
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
            return;
        
        // already visited
        if(vis[i][j] == 1)
            return;
        
        vis[i][j] = 1;
        helper(vis, grid, i-1, j);    // up
        helper(vis, grid, i+1, j);    // down
        helper(vis, grid, i, j-1);    // left
        helper(vis, grid, i, j+1);    // right
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
    
        int m = grid.size();
        int n = grid[0].size();
        
        // visited matrix
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0 && grid[i][j] != '0'){
                    ans++;
                    helper(vis, grid, i, j);
                }
            }
        }
        
        return ans;
    }
};