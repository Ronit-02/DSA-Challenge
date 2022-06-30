

class Solution {
public:
    int minMoves2(vector<int>& nums) {
  
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int mid = 0;
        if(n % 2 == 0)
            mid = nums[n/2-1];
        else
            mid = nums[n/2];
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - mid > 0)
                count += nums[i] - mid;
            else
                count += mid - nums[i];
        }
        
        return count;
    }
};