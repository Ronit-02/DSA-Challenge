class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int prevfill, int color){
        
        int m = image.size();
        int n = image[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || image[i][j] != prevfill)
            return;
        
        image[i][j] = color;
        
        dfs(image, i+1, j, prevfill, color);
        dfs(image, i, j+1, prevfill, color);
        dfs(image, i-1, j, prevfill, color);
        dfs(image, i, j-1, prevfill, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int prevfill = image[sr][sc];
        if(prevfill == color)
            return image;
        
        dfs(image, sr, sc, prevfill, color);
        
        return image;
    }
};