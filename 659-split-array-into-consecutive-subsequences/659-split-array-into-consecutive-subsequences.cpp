class Solution {
public:
    // Intuition: a new number 
    // 1. can be a part of existing group
    // 2. will start a new group
    bool isPossible(vector<int>& nums) {
        
        int n = nums.size();
        
        // availability map
        unordered_map<int, int> AM;
        for(auto x: nums)
            AM[x]++;
        
        // vacancy map
        unordered_map<int, int> VM;
        for(auto x: nums){
            
            if(AM[x] == 0)
                continue;
            
            // vacancy is there, remove, create vacancy for next
            else if(VM[x] > 0){
                AM[x]--;
                VM[x]--; VM[x+1]++;
            }
            
            // if subsequent no are present, create vacancy for next
            else if(AM[x] > 0 && AM[x+1] > 0 && AM[x+2] > 0){
                AM[x]--; AM[x+1]--; AM[x+2]--;
                VM[x+3]++;
            }
            
            else 
                return false;
        }
        
        return true;
    }
};