class Solution {
public:
    vector<vector<string>> res;
    
    int totalNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        
        back_trace(board, 0);
        
        return res.size();
        
    }
    
    void back_trace(vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        
        for(int col=0; col<board.size(); col++){
            if(is_valid(row, col, board)){
                board[row][col] = 'Q';
                back_trace(board, row+1);
                board[row][col] = '.';
            }
        }
    }
    
    bool is_valid(int row, int col, vector<string>& board){
        int n = board.size();
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }  
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
        
    }
};