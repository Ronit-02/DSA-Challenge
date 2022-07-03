class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int inc = 1;    // we increase inc when increasing slope is found
        int dec = 1;    // we increase dec when decreasing slope is found
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i-1] < nums[i])    
                inc = dec+1;             // as previous one was valley
            else if(nums[i-1] > nums[i])
                dec = inc+1;            // as previous one was mountain
        }
        
        return max(inc, dec);
    }
};