class Solution {
private:
    void recurCombSum(vector<int> candidates, int target, 
                      vector<int> comb, vector<vector<int>> &ans, int i){

        // base case
        int n = candidates.size();
        
        if(target == 0){
            sort(comb.begin(), comb.end());
            ans.push_back(comb);
            return;
        }
        
        while(i < n && target-candidates[i] >= 0){

            comb.push_back(candidates[i]);
            recurCombSum(candidates, target-candidates[i], comb, ans, i);
            i++;
            comb.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  
        vector<vector<int>> ans;
        vector<int> comb;
        
        if(candidates.size() <= 0)
            return ans;
        
        sort(candidates.begin(), candidates.end());
        recurCombSum(candidates, target, comb, ans, 0);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};