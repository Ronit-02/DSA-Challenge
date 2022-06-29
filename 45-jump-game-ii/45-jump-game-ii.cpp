class Solution {
public:
    int jump(vector<int>& nums) {
     
        // We need to keep track of farthest distance we can reach from every index
        // current represents farthest reach from 1st, 2nd, ... jump
        
        // some extra cases
        if(nums.size() == 1)
            return 0;
        if(nums[0] == 0)
            return -1;
        
        int farthest = 0;  
        int current = 0;    // we'll place a counter over that index
        int jumps = 0;
        
        for(int i = 0; i < nums.size()-1; i++){
            
            farthest = max(farthest, nums[i] + i);
            
            // indicates we have calc farthest distance b/w that index and current
            if(current == i){      
                current = farthest;
                jumps++;
            }
        }
        
        return jumps;
    }
};