class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        
        for(int i=0; i < n; i++){
            
            int idx = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            
            if(nums[i] > dp[idx-1] && nums[i] < dp[idx])
                dp[idx] = nums[i];
        }
        
        int len = 0;
        for(int i=n; i >= 0; i--){    
            if(dp[i] != INT_MAX){    
                len = i;    
                break;
            }
        }
        
        return len;
    }
};