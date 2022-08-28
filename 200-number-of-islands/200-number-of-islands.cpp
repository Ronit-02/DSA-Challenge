class Solution {
private:
    // Recursive Approach
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        // out of bounds
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        dfs(grid, i-1, j);    // up
        dfs(grid, i+1, j);    // down
        dfs(grid, i, j-1);    // left
        dfs(grid, i, j+1);    // right
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
    
        int m = grid.size();
        int n = grid[0].size();
        
        // visited matrix
        // vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != '0'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};