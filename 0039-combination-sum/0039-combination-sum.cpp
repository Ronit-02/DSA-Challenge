class Solution {
public:
    void helper(vector<int>& nums, int target, int index, vector<int> curr, vector<vector<int>> &ans){
        
        // base cases
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            // add
            curr.push_back(nums[i]);
            // recur
            helper(nums, target - nums[i], i, curr, ans);
            // remove
            curr.pop_back();  // backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        helper(nums, target, 0, curr, ans);
        return ans;
    }
};