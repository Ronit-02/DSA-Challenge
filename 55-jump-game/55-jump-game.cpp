class Solution {
public:
    bool canJump(vector<int>& nums) {
     
        int current = 0;
        int farthest = 0;
        
        for(int i = 0; i < nums.size()-1; i++){
            
            farthest = max(farthest, nums[i] + i);
            
            if(i == current)
                current = farthest;
        }
        
        if(current >= nums.size()-1)
            return true;
        else
            return false;
    }
};