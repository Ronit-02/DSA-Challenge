class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        
        while(row < m && col >= 0){
            
            int number = matrix[row][col];
            
            if(number == target)
                return true;
            
            else if(number > target){
                col--;
            }
            else{
                row++;
            }
        }
        
        return false;
    }
};