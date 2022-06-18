class Solution {
public:
    void filldfs(vector<vector<int>> &position, int n, int row, int col, int val){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==row | j==col | i+j==row+col | i-j==row-col) position[i][j]+=val;
            }
        }
    }
    
    void queens(vector<vector<string>> &result, int n, string &s, vector<string>& curr, vector<vector<int>> &position, int row_val){
        if(row_val == n) {result.push_back(curr); return;}
        for(int i=0; i<n; i++){
            if(position[row_val][i] == 0){
                s[i] = 'Q';
                curr.push_back(s);
                s[i] = '.';
                filldfs(position, n, row_val, i, 1);
                queens(result, n, s, curr, position, row_val+1);
                filldfs(position, n, row_val, i, -1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> position(n, vector<int> (n, 0));
        vector<string> curr;
        string s; 
        for(int i=0; i<n; i++) s.push_back('.');
        queens(result, n, s, curr, position, 0);
        return result;
    }
};