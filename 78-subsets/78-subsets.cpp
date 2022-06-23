class Solution {
private:
    void recurSubset(vector<int> nums, int idx, vector<int> subset, vector<vector<int>> &ans){
        
        // base case
        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }
        
        // excluding
        recurSubset(nums, idx+1, subset, ans);
        
        // including
        subset.push_back(nums[idx]);
        recurSubset(nums, idx+1, subset, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     
        vector<vector<int>> ans;
        vector<int> subset;
        
        int idx = 0;
        recurSubset(nums, idx, subset, ans);
        
        return ans;
    }
};