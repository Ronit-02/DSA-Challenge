class Solution {
public:    
    int nthUglyNumber(int n) {
        
        // As Ugly Numbers are mulitples of 2,3,5
        // So we'll start with 2,3,5 and compute multiples of it
        
        vector<int>dp(n);
        dp[0] = 1;       // 1 is an ugly number
        
        int p2 = 0;   // pointer for 2
        int p3 = 0;   // for 3
        int p5 = 0;   // for 5
        
        for(int i=1; i<n; i++){
            
            int multipleof2 = dp[p2]*2;
            int multipleof3 = dp[p3]*3;
            int multipleof5 = dp[p5]*5;
            
            int mi = min(multipleof2, min(multipleof3, multipleof5));
            dp[i] = mi;
            
            if(dp[i] == multipleof2) p2++;     // not using else if to eliminate duplicate values
            if(dp[i] == multipleof3) p3++;     // eg. 6 is multiple of both 2,3 
            if(dp[i] == multipleof5) p5++;     // so pointer will be increased for both 2 and 3 
        }
        
        return dp[n-1];
    }
};