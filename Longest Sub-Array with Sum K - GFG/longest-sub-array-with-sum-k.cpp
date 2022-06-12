// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int maxlen = 0;
        int sum = 0;
        
        unordered_map<int, int> hash;
        
        for(int i=0; i<n; i++){
            
            sum += arr[i];
            
            
            if(sum == k){
                maxlen = i+1;
            }
            
            if (hash.find(sum) == hash.end())
                hash[sum] = i;
            
            if(hash.find(sum - k) != hash.end()){
                maxlen = max(maxlen, (i - hash[sum-k]));
            }
        }
        
        return maxlen;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends