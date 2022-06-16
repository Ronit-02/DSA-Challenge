// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n];   
        int len = 0;
        
        for(int i=0; i<n; i++){
            
            dp[i] = 1;     // every element is a increasing subsequence by itself
            for(int j=0; j<i; j++){     // checking bwds in dp array for smaller value
                
                if(a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);    // dp[j] + 1 -> dp[j] subsequence + for i
            }
            
            len = max(len, dp[i]);
        }
        
        return len;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends