class Solution {
public:
    int currArea(int i, int j, vector<vector<int>>& grid){
        
        // base case
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
            
        grid[i][j] = 0;
        int up = currArea(i-1, j, grid);
        int down = currArea(i+1, j, grid);
        int left = currArea(i, j-1, grid);
        int right = currArea(i, j+1, grid);
        
        return up + down + left + right + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, currArea(i, j, grid));
            }
        }
        
        return maxArea;
    }
};