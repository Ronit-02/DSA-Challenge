class Solution {
private:
    void recurParan(int n, int i, int open, int close, string comb, vector<string> &ans){
        
        // base case
        if(i == 2*n){
            ans.push_back(comb);
            return;
        }
        
        if(open < n){
            comb += '(';
            recurParan(n, i+1, open+1, close, comb, ans);
            comb.pop_back();
        }
        if(close < open){
            comb += ')';
            recurParan(n, i+1, open, close+1, comb, ans);
            comb.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
    
        vector<string> ans;
        string comb;
        
        int i = 0;
        recurParan(n, i, 0, 0, comb, ans);
        
        return ans;
    }
};