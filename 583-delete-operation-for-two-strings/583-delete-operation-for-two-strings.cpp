class Solution {
public:
    int t[100][100];
    
    // Largest common substring using memoization
    int LCS(string word1, string word2, int m, int n){
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0)); 
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0) 
                    continue;
                
                else if(word1[i-1]==word2[j-1])     // equal -> take both of them
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else                                // not equal -> remove 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        // calling function
        int len = LCS(word1, word2, m, n);
        
        int ans = (m-len) + (n-len);
        
        return ans;
    }
};