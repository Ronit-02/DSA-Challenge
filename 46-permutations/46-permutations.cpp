class Solution {
public:
    vector<vector<int>> ans;
    
    void recurPermute(vector<int> nums, int index){
        
        // base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=index; j<nums.size(); j++){
            
            swap(nums[index], nums[j]);
            recurPermute(nums, index+1);
            swap(nums[index], nums[j]);    // Backtracking
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        recurPermute(nums, 0);
        
        return ans;
    }
};