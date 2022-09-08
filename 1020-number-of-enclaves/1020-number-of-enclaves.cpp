class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis, int rows[], int cols[]){
         
        int n = grid.size();
        int m = grid[0].size();
        
        vis[r][c] = 1;
        
        // traversing in 4 directions
        for(int i=0; i<4; i++){
            int nr = r + rows[i];
            int nc = c + cols[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 1)
                dfs(nr, nc, grid, vis, rows, cols);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        
        // Step 1: Mark boundary and connected as visited
        for(int j=0; j<m; j++){
            
            // first row
            if(!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, grid, vis, rows, cols);
            // last row
            if(!vis[n-1][j] && grid[n-1][j] == 1)
                dfs(n-1, j, grid, vis, rows, cols);
        }
        for(int i=0; i<n; i++){
            
            // first column
            if(!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, grid, vis, rows, cols);
            // last column
            if(!vis[i][m-1] && grid[i][m-1] == 1)
                dfs(i, m-1, grid, vis, rows, cols);
        }
            
        int ans = 0;
        
        // Step 2: Non visited 1's are answer
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }
};