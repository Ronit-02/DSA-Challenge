class Solution {
private:
    void recurCombSum(vector<int> &candidates, int target, vector<int> comb, vector<vector<int>> &ans, int i){
        
        // base case
        if(i == candidates.size()){
            if(target == 0){
                // sort(comb.begin(), comb.end());
                ans.push_back(comb);
            }
            return;
        }
        
        // take
        if(candidates[i] <= target){

            comb.push_back(candidates[i]);
            recurCombSum(candidates, target-candidates[i], comb, ans, i);
            comb.pop_back();
        }
        
        // not take
        recurCombSum(candidates, target, comb, ans, i+1);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  
        vector<vector<int>> ans;
        vector<int> comb;
        
        recurCombSum(candidates, target, comb, ans, 0);
        
        return ans;
    }
};