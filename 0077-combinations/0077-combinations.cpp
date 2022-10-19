class Solution {
public:
    // Intuition: Backtracking
    void helper(int n, int k, int i, vector<int> curr, vector<vector<int>> & ans){
        
        // base case
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        
        for(int j=i; j<=n; j++){
            // add
            curr.push_back(j);
            // recur
            helper(n, k, j+1, curr, ans);
            // remove
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        helper(n, k, 1, curr, ans);
        
        return ans;
    }
};