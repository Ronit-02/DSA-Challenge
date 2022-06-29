class Solution {
public:
    bool canJump(vector<int>& nums) {
     
        int current = 0;     // represents index after 1st, 2nd, .. jump
        int farthest = 0;    // farthest distance from every index
        
        for(int i = 0; i < nums.size()-1; i++){
            
            farthest = max(farthest, nums[i] + i);
            
            if(i == current)   // exhausted every possibility from 1st, 2nd, ... jump
                current = farthest;
        }
        
        if(current >= nums.size()-1)
            return true;
        else
            return false;
    }
};