class Solution {
public:
    void recurPermute(vector<int> nums, int index, vector<vector<int>> &ans){
        
        // base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=index; j<nums.size(); j++){
            
            swap(nums[index], nums[j]);
            recurPermute(nums, index+1, ans);
            swap(nums[index], nums[j]);    // Backtracking
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int index = 0;
        recurPermute(nums, index, ans);
        
        return ans;
    }
};