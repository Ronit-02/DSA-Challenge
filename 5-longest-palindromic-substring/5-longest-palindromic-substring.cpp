class Solution {
public:
    string longestPalindrome(string s) {
        
        // DP Matrix Approach
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int len = 0;  
        string ans;
        
        for(int diff=0; diff < n; diff++){   // as we are looking for diagonal elements, diff(i,j) inc..
            
            for(int i=0,j=i+diff ; j<n; j++, i++){
                
                if(i == j)      //  Primary diagonal -> a,b,c are all palindrome of lenghts 1
                    dp[i][j] = 1;
                
                else if(diff == 1){    // Secondary diagonal -> ab,ba,aa,bb
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                    }
                    else
                        dp[i][j] = 0;
                }
                 
                else{                     // every other diagonal
                    if(s[i] == s[j] && dp[i+1][j-1] > 0)
                        dp[i][j] = dp[i+1][j-1] + 2;
                }
                
                if(dp[i][j] > 0){   // to store the corresponding string
                
                    if(j-i+1 > len){
                        len = j-i+1;
                        ans = s.substr(i, len);
                    }
                }    
            }
        }
        return ans;
    }
};