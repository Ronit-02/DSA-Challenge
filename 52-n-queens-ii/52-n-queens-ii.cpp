#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool isSafe(int n, int row, int col, vector<string> board){
    
        // Same Row
        for(int i=0; i<n; i++){
            if(board[row][i] == 'Q')
                return false;
        }
        // Primary Diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }
        // Secondary Diagonal
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void recurnQueen(int n, int col, vector<string>& board, vector<vector<string>> &ans){
        
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){      
            if(isSafe(n, row, col, board)){
                
                board[row][col] = 'Q';     // Add
                recurnQueen(n, col+1, board, ans);   // Recur
                board[row][col] = '.';      // Backtrack
            }
        }
    }

    int totalNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        int col = 0;
        recurnQueen(n, col, board, ans);
        
        return ans.size();
    }
};