class Solution {
public:
    int numSquares(int n) {
     
        // DP Approach Tabulation Method
        // start from no. itself and check value at each break points
        
        vector<int> dp(n+1);
        
        if(n <= 3)       // Minimum Condition
            return n; 
        
        int i = 0;
        while(i <= n){
            dp[i] = i;   // for 1^2 break points, eg: 3 = 1^2 + 1^2 + 1^2
            
            for(int j=1; j*j <= i; j++)    // for 2^2 and above break points
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            
            i++;
        }
         
        return dp[n];
    }
};